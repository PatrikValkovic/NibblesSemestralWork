#include "NetGameState.h"

GameStates::AbstractGameState* GameStates::NetGameState::run()
{
    using ViewModel::NetMenuConsoleViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;
    using Game::Event::ServerSide;

    NetMenuConsoleViewModel* Rendering = (NetMenuConsoleViewModel*) this->RenderingModel->NetModel();

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
            return this->Menu;
        }

        Server->StartServer();
    }
    else
        while (ClientSock == -1)
        {
            pair<string, string> ServerIPWithPort = Rendering->GetIPAndPort();
            ClientSock = ConnectToServer(ServerIPWithPort);
            if(ClientSock==-1)
            {
                Rendering->CannotConnect();
                continue;
            }
        }

    //run base connections
    //create tasks and events

    return NULL;
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









