#include "NetGameState.h"

GameStates::AbstractGameState* GameStates::NetGameState::run()
{
    using ViewModel::NetMenuAbstractViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;
    using Game::GameContent;
    using Game::NetworkCommunication;
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
    NetworkCommunication::SendHello(ClientSock);
    if (!NetworkCommunication::RecvHello(ClientSock))
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
    CreatedContent->Worms = Worms;
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
    using Game::NetworkCommunication;
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
            ServerSock = NetworkCommunication::CreateServerSocket(ServerIPWithPort, CountOfPlayers);
            if (ServerSock == -1)
                Rendering->ServerNotCreated();
            else
                Rendering->ServerCreated();
        }

        ServerSide* Server = new ServerSide(ServerSock, CountOfPlayers, NewPlayGround);

        //connect to it
        ClientSock = NetworkCommunication::CreateClientSocket(ServerIPWithPort);
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
            ClientSock = NetworkCommunication::CreateClientSocket(ServerIPWithPort);
            if (ClientSock == -1)
            {
                Rendering->CannotConnect();
                continue;
            }
        }

    return ClientSock;
}













