#ifdef USE_SDL
#include "NetMenuSDLViewModel.h"


ViewModel::NetMenuSDLViewModel::NetMenuSDLViewModel(const Translate::TranslateEngine* Translation)
        : NetMenuAbstractViewModel(Translation)
{ }

string ViewModel::NetMenuSDLViewModel::Level()
{
    return "";
}

int ViewModel::NetMenuSDLViewModel::CountOfPlayers(int Max)
{
    return 0;
}

pair<string, string> ViewModel::NetMenuSDLViewModel::GetIPAndPort()
{
    using namespace std;
    return pair<string,string>("","");
}

bool ViewModel::NetMenuSDLViewModel::CreateNewServer()
{
    return false;
}

void ViewModel::NetMenuSDLViewModel::ServerCreated()
{

}

void ViewModel::NetMenuSDLViewModel::ServerNotCreated()
{

}

void ViewModel::NetMenuSDLViewModel::CreatingAndConnectingError()
{

}

void ViewModel::NetMenuSDLViewModel::CannotConnect()
{

}

void ViewModel::NetMenuSDLViewModel::ServerNotRespond()
{

}

void ViewModel::NetMenuSDLViewModel::ServerRespond()
{

}

void ViewModel::NetMenuSDLViewModel::LevelToUse(string NameOfLevel)
{

}

void ViewModel::NetMenuSDLViewModel::HaveMap(bool Have)
{

}

string ViewModel::NetMenuSDLViewModel::GetName()
{
    return __cxx11::basic_string<char, char_traits<char>, allocator<char>>();
}

void ViewModel::NetMenuSDLViewModel::PlayerConnected(string NameOfPlayer)
{

}

void ViewModel::NetMenuSDLViewModel::BeginGame()
{

}

void ViewModel::NetMenuSDLViewModel::WaitingForRestOfPlayers()
{

}


#endif



