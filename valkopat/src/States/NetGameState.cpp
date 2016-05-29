#include "NetGameState.h"

GameStates::AbstractGameState* GameStates::NetGameState::run()
{
    using ViewModel::NetMenuAbstractViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;
    using Game::GameContent;
    using Game::Event::ServerSide;
    using Game::Event::ClientSide;
    using Game::Task::DiscardingInput;
    using Game::Task::ServerListener;

    NetMenuAbstractViewModel* Rendering = this->RenderingModel->NetModel();

    string NameOfPlayer = Rendering->GetName();
    int ClientSock = CreateSocket();
    if (ClientSock == -1)
        return this->Menu;

    ClientSide* ClientSideEvent = new ClientSide(ClientSock,this->RenderingModel->InputModel());
    if (!ClientSideEvent->SendHello())
    {
        delete ClientSideEvent;
        Rendering->ServerNotRespond();
        return this->Menu;
    }
    Rendering->ServerRespond();
    pair<string, size_t> LevelNameAndLength = ClientSideEvent->LevelInfo();

    vector<Worm*> Worms;
    PlayGround* CreatedPlayground = this->CreatePlayground(LevelNameAndLength, ClientSideEvent);
    Worm* PlayerWorm = ClientSideEvent->AskToWorm(NameOfPlayer);
    Worms.push_back(PlayerWorm);

    Rendering->WaitingForRestOfPlayers();

    while((PlayerWorm = ClientSideEvent->PlayerConnected()) != NULL)
    {
        Worms.push_back(PlayerWorm);
        Rendering->PlayerConnected(PlayerWorm->GetName());
    }
    Rendering->BeginGame();

    GameContent* CreatedContent = new GameContent();
    CreatedContent->Players = Worms;
    CreatedContent->Events.AddEvent(ClientSideEvent);
    CreatedContent->Ground = CreatedPlayground;

    ServerListener* ServerListenTask = new ServerListener(ClientSock,CreatedContent->Worms);
    DiscardingInput* DiscardTask = new DiscardingInput(this->RenderingModel->InputModel());
    CreatedContent->Tasks.push_back(ServerListenTask);
    CreatedContent->Tasks.push_back(DiscardTask);

    this->PlayState->ClearContent(CreatedContent);
    return this->PlayState;

}

GameStates::NetGameState::NetGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::NetGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->PlayState = GameState;
    this->Menu = MenuState;
}

int GameStates::NetGameState::CreateServer(std::pair<string, string> IPAndPort, int CountOfPlayers)
{
    //ZDROJ: https://edux.fit.cvut.cz/courses/BI-PA2/semestralka
    struct addrinfo* ai;

    if (getaddrinfo(IPAndPort.first.c_str(), IPAndPort.second.c_str(), NULL, &ai) != 0)
    {
        //printf ( "getaddrinfo\n" );
        return -1;
    }

    int s = socket(ai->ai_family, SOCK_STREAM, 0);
    if (s == -1)
    {
        freeaddrinfo(ai);
        //printf ( "socket\n" );
        return -1;
    }

    if (bind(s, ai->ai_addr, ai->ai_addrlen) != 0)
    {
        close(s);
        freeaddrinfo(ai);
        //printf ( "bind\n" );
        return -1;
    }

    if (listen(s, CountOfPlayers) != 0)
    {
        close(s);
        freeaddrinfo(ai);
        //printf ( "listen\n" );
        return -1;
    }
    freeaddrinfo(ai);
    return s;
}

int GameStates::NetGameState::ConnectToServer(std::pair<string, string> IPAndPort)
{
    //ZDROJ: https://edux.fit.cvut.cz/courses/BI-PA2/semestralka
    struct addrinfo* ai;

    if (getaddrinfo(IPAndPort.first.c_str(), IPAndPort.second.c_str(), NULL, &ai) != 0)
    {
        //printf ( "getaddrinfo" );
        return -1;
    }

    int s = socket(ai->ai_family, SOCK_STREAM, 0);
    if (s == -1)
    {
        freeaddrinfo(ai);
        //printf ( "socket" );
        return -1;
    }

    if (connect(s, ai->ai_addr, ai->ai_addrlen) != 0)
    {
        close(s);
        freeaddrinfo(ai);
        //printf ( "connect" );
        return -1;
    }
    freeaddrinfo(ai);
    return s;
}

Game::PlayGround* GameStates::NetGameState::CreatePlayground(pair<string, size_t> NameOfLevel,
                                                             Game::Event::ClientSide* Client)
{
    using ViewModel::NetMenuAbstractViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;

    NetMenuAbstractViewModel* Rendering = this->RenderingModel->NetModel();
    Rendering->LevelToUse(NameOfLevel.first);

    try
    {
        string LevelContent = PlaygroundFactory::GetLevelInString(NameOfLevel.first);
        std::hash<std::string> HashFn;
        if(HashFn(LevelContent)!=NameOfLevel.second)
            throw new Exceptions::Exception("Hash of maps are not equal");
        stringstream Stream(LevelContent);
        Rendering->HaveMap(true);
        Client->AskToLevel(true);
        return PlaygroundFactory::ParseLevelFromStream(Stream);
    }
    catch(Exceptions::Exception* e)
    {
        delete e;
    }

    Rendering->HaveMap(false);
    string Level = Client->AskToLevel(false);
    stringstream Stream(Level);
    return PlaygroundFactory::ParseLevelFromStream(Stream);
}

int GameStates::NetGameState::CreateSocket()
{
    using ViewModel::NetMenuAbstractViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;
    using Game::Event::ServerSide;
    using Game::Event::ClientSide;

    NetMenuAbstractViewModel* Rendering = this->RenderingModel->NetModel();

    int ClientSock = -1;
    if (Rendering->CreateNewServer())
    {
        //create server
        string LevelName = Rendering->Level();
        PlayGround* NewPlayGround = PlaygroundFactory::GetLevel(LevelName);
        int CountOfPlayers = Rendering->CountOfPlayers(NewPlayGround->CountOfStartPositions());
        int ServerSock = -1;
        pair<string, string> ServerIPWithPort;
        while (ServerSock == -1)
        {
            ServerIPWithPort = Rendering->GetIPAndPort();
            ServerSock = this->CreateServer(ServerIPWithPort, CountOfPlayers);
            if (ServerSock == -1)
                Rendering->ServerNotCreated();
            else
                Rendering->ServerCreated();
        }

        ServerSide* Server = new ServerSide(ServerSock, CountOfPlayers, NewPlayGround);

        //connect to it
        ClientSock = ConnectToServer(ServerIPWithPort);
        if (ClientSock == -1)
        {
            delete Server;
            Rendering->CreatingAndConnectingError();
            return -1;
        }   

        Server->StartServer();
    }
    else
        while (ClientSock == -1)
        {
            pair<string, string> ServerIPWithPort = Rendering->GetIPAndPort();
            ClientSock = ConnectToServer(ServerIPWithPort);
            if (ClientSock == -1)
            {
                Rendering->CannotConnect();
                continue;
            }
        }

    return ClientSock;
}













