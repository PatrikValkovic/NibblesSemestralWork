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

    if (!this->SayHello(ClientSock))
        return this->Menu;

    PlayGround* CreatedPlayground = this->CreatePlayground(ClientSock);
    Worm* PlayerWorm = this->GetInfoAboutPlayer(ClientSock,NameOfPlayer);

    ClientSide* ClientSideEvent = new ClientSide(ClientSock,this->RenderingModel->InputModel());

    vector<Worm*> Worms;
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

Game::PlayGround* GameStates::NetGameState::CreatePlayground(int Socket)
{
    using ViewModel::NetMenuAbstractViewModel;
    using Game::NetworkCommunication;
    using Game::PlayGround;
    using Game::PlaygroundFactory;

    NetMenuAbstractViewModel* Rendering = this->RenderingModel->NetModel();
    string NameOfLevel;
    size_t HashOfLevel;

    NetworkCommunication::RecvMapRequest(Socket,NameOfLevel,HashOfLevel);

    try
    {
        string LevelContent = PlaygroundFactory::GetLevelInString(NameOfLevel);
        std::hash<std::string> HashFn;
        if(HashFn(LevelContent)!=HashOfLevel)
            throw new Exceptions::Exception("Hash of maps are not equal");
        NetworkCommunication::SendMapRequestAnswer(Socket,true);
        Rendering->HaveMap(true);

        stringstream Stream(LevelContent);
        return PlaygroundFactory::ParseLevelFromStream(Stream);
    }
    catch(Exceptions::Exception* e)
    {
        delete e;
    }

    Rendering->HaveMap(false);
    NetworkCommunication::SendMapRequestAnswer(Socket,false);

    string LevelContent;
    NetworkCommunication::RecvMapTransfer(Socket,NameOfLevel,LevelContent);
    //TODO Save map locally
    stringstream Stream(LevelContent);
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

bool GameStates::NetGameState::SayHello(int Socket)
{
    using Game::NetworkCommunication;

    NetworkCommunication::SendHello(Socket);
    if (!NetworkCommunication::RecvHello(Socket))
    {
        this->RenderingModel->NetModel()->ServerNotRespond();
        return false;
    }
    this->RenderingModel->NetModel()->ServerRespond();
}

Game::Worm* GameStates::NetGameState::GetInfoAboutPlayer(int Socket, string Name)
{
    using namespace Game;

    NetworkCommunication::SendName(Socket,Name);

    int PosX;
    int PosY;
    Actions BeginDirection;
    int PlayerID;
    NetworkCommunication::RecvInitForPlayer(Socket,PosX,PosY,BeginDirection,PlayerID);

    //TODO what about ID?
    Worm* CreatedWorm = new Worm(PosX,PosY,BeginDirection,PlayerID);
    CreatedWorm->SetName(Name);
    return CreatedWorm;
}

















