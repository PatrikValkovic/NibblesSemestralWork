#include "NetGameState.h"
#include <iostream>
GameStates::AbstractGameState* GameStates::NetGameState::run()
{
    using ViewModel::NetMenuConsoleViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;

    NetMenuConsoleViewModel* Rendering = (NetMenuConsoleViewModel*)this->RenderingModel->NetModel();

    if(Rendering->CreateNewServer())
    {
        string LevelName = Rendering->Level();
        PlayGround* NewPlayGround = PlaygroundFactory::GetLevel(LevelName);
        int CountOfPlayers = Rendering->CountOfPlayers(NewPlayGround->CountOfStartPositions());
        int ServerSock = -1;
        while(ServerSock==-1)
        {
            pair<string, string> ServerIPWithPort = Rendering->GetServerIPAndPort();
            ServerSock = this->CreateServer(ServerIPWithPort, CountOfPlayers);
            if(ServerSock==-1)
                Rendering->ServerNotCreated();
            else
                Rendering->ServerCreated();
        }
        //TODO run in separate thread
    }
    else
    {
        //TODO ask for IP to connect
    }

    //connect to server

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
    struct addrinfo * ai;

    if ( getaddrinfo ( IPAndPort.first.c_str(), IPAndPort.second.c_str(), NULL, &ai ) != 0 )
    {
        printf ( "getaddrinfo\n" );
        return -1;
    }

    int s = socket ( ai -> ai_family, SOCK_STREAM, 0 );
    if ( s == -1 )
    {
        freeaddrinfo ( ai );
        printf ( "socket\n" );
        return -1;
    }

    if ( bind ( s, ai -> ai_addr, ai -> ai_addrlen ) != 0 )
    {
        close ( s );
        freeaddrinfo ( ai );
        printf ( "bind\n" );
        return -1;
    }

    if ( listen ( s, CountOfPlayers ) != 0 )
    {
        close ( s );
        freeaddrinfo ( ai );
        printf ( "listen\n" );
        return -1;
    }
    freeaddrinfo ( ai );
    return s;
}







