#include "NetMenuNCursesViewModel.h"
#ifdef USE_NCURSES

ViewModel::NetMenuNCursesVIewModel::NetMenuNCursesVIewModel(const Translate::TranslateEngine* Translation)
        : NetMenuAbstractViewModel(Translation)
{ }

string ViewModel::NetMenuNCursesVIewModel::Level()
{
    return "";
}

int ViewModel::NetMenuNCursesVIewModel::CountOfPlayers(int Max)
{
    return 0;
}

std::pair<std::string, std::string> ViewModel::NetMenuNCursesVIewModel::GetIPAndPort()
{
    using namespace std;
    return pair<string,string>("","");
}

bool ViewModel::NetMenuNCursesVIewModel::CreateNewServer()
{
    return false;
}

void ViewModel::NetMenuNCursesVIewModel::ServerCreated()
{

}

void ViewModel::NetMenuNCursesVIewModel::ServerNotCreated()
{

}

void ViewModel::NetMenuNCursesVIewModel::CreatingAndConnectingError()
{

}

void ViewModel::NetMenuNCursesVIewModel::CannotConnect()
{

}

void ViewModel::NetMenuNCursesVIewModel::ServerNotRespond()
{

}

void ViewModel::NetMenuNCursesVIewModel::ServerRespond()
{

}

void ViewModel::NetMenuNCursesVIewModel::LevelToUse(string NameOfLevel)
{

}

void ViewModel::NetMenuNCursesVIewModel::HaveMap(bool Have)
{

}

string ViewModel::NetMenuNCursesVIewModel::GetName()
{
    return "";
}

void ViewModel::NetMenuNCursesVIewModel::PlayerConnected(string NameOfPlayer)
{

}

void ViewModel::NetMenuNCursesVIewModel::BeginGame()
{

}

void ViewModel::NetMenuNCursesVIewModel::WaitingForRestOfPlayers()
{

}


#endif

