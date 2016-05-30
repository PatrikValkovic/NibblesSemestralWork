#include "NetworkCommunication.h"

void Game::NetworkCommunication::SendHeader(int Socket, Game::ServerActions Header)
{
    send(Socket, &Header, sizeof(Game::ServerActions), 0);
}

Game::ServerActions Game::NetworkCommunication::RecvHeader(int Socket)
{
    using namespace std;
    ServerActions Recived;
    recv(Socket, &Recived, sizeof(ServerActions), 0);
    return Recived;
}

void Game::NetworkCommunication::SendHello(int Socket)
{
    SendHeader(Socket, ServerActions::Hello);
}

void Game::NetworkCommunication::RecvHello(int Socket)
{
    //TODO implemented waiting specific time
    if (RecvHeader(Socket) != ServerActions::Hello)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);
}

void Game::NetworkCommunication::SendMapRequest(int Socket, string Name, size_t Hash)
{
    size_t MapSize = Name.size();

    SendHeader(Socket, ServerActions::RequiredMap);
    send(Socket, &MapSize, sizeof(size_t), 0);
    send(Socket, Name.data(), MapSize, 0);
    send(Socket, &Hash, sizeof(size_t), 0);
}

void Game::NetworkCommunication::RecvMapRequest(int Socket, string& Name, size_t& Hash)
{
    if (RecvHeader(Socket) != ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

    size_t SizeOfMap;
    recv(Socket, &SizeOfMap, sizeof(size_t), 0);

    char* Buffer = (char*) calloc(SizeOfMap + 1, 1);
    recv(Socket, Buffer, SizeOfMap, 0);
    Name = string(Buffer);
    free(Buffer);

    recv(Socket, &Hash, sizeof(size_t), 0);
}

void Game::NetworkCommunication::SendMapRequestAnswer(int Socket, bool Have)
{
    SendHeader(Socket, ServerActions::RequiredMap);
    send(Socket, &Have, sizeof(bool), 0);
}

void Game::NetworkCommunication::RecvMapRequestAnswer(int Socket, bool& Have)
{
    if (RecvHeader(Socket) != ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

    recv(Socket, &Have, sizeof(bool), 0);
}

void Game::NetworkCommunication::SendMapTransfer(int Socket, string Name, string Data)
{
    SendHeader(Socket, ServerActions::MapTransfer);

    size_t SizeOfName = Name.size();
    size_t SizeOfData = Data.size();

    send(Socket, &SizeOfName, sizeof(size_t), 0);
    send(Socket, Name.data(), SizeOfName, 0);
    send(Socket, &SizeOfData, sizeof(size_t), 0);
    send(Socket, Data.data(), SizeOfData, 0);
}

void Game::NetworkCommunication::RecvMapTransfer(int Socket, string& Name, string& Data)
{
    if (RecvHeader(Socket) != ServerActions::MapTransfer)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

    size_t SizeOfName;
    size_t SizeOfData;
    char* NameBuffer;
    char* DataBuffer;

    recv(Socket, &SizeOfName, sizeof(size_t), 0);
    NameBuffer = (char*) calloc(SizeOfName + 1, 1);
    recv(Socket, NameBuffer, SizeOfName, 0);
    Name = string(NameBuffer);

    recv(Socket, &SizeOfData, sizeof(size_t), 0);
    DataBuffer = (char*) calloc(SizeOfData + 1, 1);
    recv(Socket, DataBuffer, SizeOfData, 0);
    Name = string(DataBuffer);

    free(NameBuffer);
    free(DataBuffer);
}

void Game::NetworkCommunication::SendName(int Socket, string Name)
{
    SendHeader(Socket, ServerActions::NameTransfer);

    size_t LengthOfName = Name.size();
    send(Socket, &LengthOfName, sizeof(size_t), 0);
    send(Socket, Name.data(), LengthOfName, 0);
}

void Game::NetworkCommunication::RecvName(int Socket, string& Name)
{
    if (RecvHeader(Socket) != ServerActions::NameTransfer)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

    size_t LengthOfName;
    char* Buffer;

    recv(Socket, &LengthOfName, sizeof(size_t), 0);
    Buffer = (char*) calloc(LengthOfName + 1, 0);
    recv(Socket, Buffer, LengthOfName, 0);
    Name = string(Buffer);

    free(Buffer);
}

void Game::NetworkCommunication::SendInitForPlayer(int Socket, int PosX, int PosY, Actions Direction)
{
    SendHeader(Socket, ServerActions::InitTransfer);

    send(Socket, &PosX, sizeof(int), 0);
    send(Socket, &PosY, sizeof(int), 0);
    send(Socket, &Direction, sizeof(Actions), 0);
}

void Game::NetworkCommunication::RecvInitForPlayer(int Socket, int& PosX, int PosY, Actions& Direction)
{
    if (RecvHeader(Socket) != ServerActions::InitTransfer)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

    recv(Socket, &PosX, sizeof(int), 0);
    recv(Socket, &PosY, sizeof(int), 0);
    recv(Socket, &Direction, sizeof(Actions), 0);
}

void Game::NetworkCommunication::SendPlayerConnected(int Socket, string NameOfPlayer, int PosX, int PosY,
                                                     Actions Direction)
{
    SendHeader(Socket, ServerActions::PlayerConnected);

    size_t LengthOfName = NameOfPlayer.size();
    send(Socket, &LengthOfName, sizeof(size_t), 0);
    send(Socket, NameOfPlayer.data(), LengthOfName, 0);
    send(Socket, &PosX, sizeof(int), 0);
    send(Socket, &PosY, sizeof(int), 0);
    send(Socket, &Direction, sizeof(Actions), 0);
}

void Game::NetworkCommunication::SendStartGame(int Socket)
{
    SendHeader(Socket, ServerActions::StartGame);
}

bool Game::NetworkCommunication::TryRecvPlayerConnected(int Socket, string& NameOfPlayer, int& PosX, int& PosY,
                                                        Actions& Direction)
{
    ServerActions Obtained = RecvHeader(Socket);
    if (Obtained == ServerActions::StartGame)
        return false;

    if (Obtained != ServerActions::PlayerConnected)
        throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

    size_t LengthOfName;
    char* NameBuffer;
    recv(Socket, &LengthOfName, sizeof(size_t), 0);
    NameBuffer = (char*) calloc(LengthOfName + 1, 1);
    recv(Socket, NameBuffer, LengthOfName, 0);
    NameOfPlayer = string(NameBuffer);
    free(NameBuffer);

    recv(Socket, &PosX, sizeof(int), 0);
    recv(Socket, &PosY, sizeof(int), 0);
    recv(Socket, &Direction, sizeof(Actions), 0);
}

void Game::NetworkCommunication::SendPlayerAction(int Socket, Actions Action)
{
    SendHeader(Socket,ServerActions::KeyStroke);

    send(Socket,&Action,sizeof(Actions),0);
}

bool Game::NetworkCommunication::TryRecvPlayerAction(int Socket, Actions& Action)
{
    ServerActions Recived;
    if(recv(Socket,&Recived,sizeof(ServerActions),MSG_DONTWAIT)!=-1)
    {
        if(Recived!=ServerActions::KeyStroke)
            throw new Exceptions::ServerException("Invalid header", __LINE__, __FILE__);

        recv(Socket,&Action,sizeof(Actions),0);
        return true;
    }
    return false;
}

void Game::NetworkCommunication::SendActionsOfPlayer(int Socket, int IDOfPlayer, Actions Action)
{
    SendHeader(Socket,ServerActions::ActionsSend);
    send(Socket,&IDOfPlayer,sizeof(int),0);
    send(Socket,&Action,sizeof(Action),0);
}

void Game::NetworkCommunication::SendEndOfWait(int Socket)
{
    SendHeader(Socket,ServerActions::Wait);
}

bool Game::NetworkCommunication::TryRecvActionsOfPlayer(int Socket, int& IDOfPlayer, Actions& Action)
{
    ServerActions Obtained = RecvHeader(Socket);
    if(Obtained == ServerActions::Wait)
        return false;

    recv(Socket,&IDOfPlayer,sizeof(int),0);
    recv(Socket,&Action,sizeof(Actions),0);
    return true;
}

int Game::NetworkCommunication::CreateServerSocket(pair<string, string> IPAndPort,int CountOfPlayers)
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

int Game::NetworkCommunication::CreateClientSocket(pair<string, string> IPAndPort)
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

















































