#include "NetworkCommunication.h"

void Game::NetworkCommunication::SendHeader(int Socket, Game::ServerActions Header)
{
    send(Socket,&Header,sizeof(Game::ServerActions),0);
}

ServerActions Game::NetworkCommunication::RecvHeader(int Socket)
{
    using namespace std;
    ServerActions Recived;
    recv(Socket,&Recived,sizeof(ServerActions),0);
    return Recived;
}

void Game::NetworkCommunication::SendHello(int Socket)
{
    SendHeader(Socket,ServerActions::Hello);
}

void Game::NetworkCommunication::RecvHello(int Socket)
{
    if(RecvHeader(Socket)!=ServerActions::Hello)
        throw new Exceptions::ServerException("Invalid header",__LINE__,__FILE__);
}

void Game::NetworkCommunication::SendMapRequest(int Socket, string Name, size_t Hash)
{
    size_t MapSize = Name.size();

    SendHeader(Socket,ServerActions::RequiredMap);
    send(Socket,&MapSize,sizeof(size_t),0);
    send(Socket,Name.data(),MapSize,0);
    send(Socket,&Hash,sizeof(size_t),0);
}

void Game::NetworkCommunication::RecvMapRequest(int Socket, string& Name, size_t& Hash)
{
    if(RecvHeader(Socket)!=ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header",__LINE__,__FILE__);

    size_t SizeOfMap;
    recv(Socket,&SizeOfMap,sizeof(size_t),0);

    char* Buffer = (char*)calloc(SizeOfMap+1,1);
    recv(Socket,Buffer,SizeOfMap,0);
    Name = string(Buffer);
    free(Buffer);

    recv(Socket,&Hash,sizeof(size_t),0);
}

void Game::NetworkCommunication::SendMapRequestAnswer(int Socket, bool Have)
{
    SendHeader(Socket,ServerActions::RequiredMap);
    send(Socket,&Have,sizeof(bool),0);
}

void Game::NetworkCommunication::RecvMapRequestAnswer(int Socket, bool& Have)
{
    if(RecvHeader(Socket)!=ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header",__LINE__,__FILE__);

    recv(Socket,&Have,sizeof(bool),0);
}

void Game::NetworkCommunication::SendMapTransfer(int Socket, string Name, string Data)
{
    SendHeader(Socket,ServerActions::MapTransfer);

    size_t SizeOfName = Name.size();
    size_t SizeOfData = Data.size();

    send(Socket,&SizeOfName,sizeof(size_t),0);
    send(Socket,Name.data(),SizeOfName,0);
    send(Socket,&SizeOfData,sizeof(size_t),0);
    send(Socket,Data.data(),SizeOfData,0);
}

void Game::NetworkCommunication::RecvMapTransfer(int Socket, string& Name, string& Data)
{
    if(RecvHeader(Socket)!=ServerActions::MapTransfer)
        throw new Exceptions::ServerException("Invalid header",__LINE__,__FILE__);

    size_t SizeOfName;
    size_t SizeOfData;
    char* NameBuffer;
    char* DataBuffer;

    recv(Socket,&SizeOfName,sizeof(size_t),0);
    NameBuffer = (char*)calloc(SizeOfName+1,1);
    recv(Socket,NameBuffer,SizeOfName,0);
    Name = string(NameBuffer);

    recv(Socket,&SizeOfData,sizeof(size_t),0);
    DataBuffer = (char*)calloc(SizeOfData+1,1);
    recv(Socket,DataBuffer,SizeOfData,0);
    Name = string(DataBuffer);

    free(NameBuffer);
    free(DataBuffer);
}



















