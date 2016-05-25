#ifdef USE_SDL
#include "SingpleplayerMenuSDLViewModel.h"


ViewModel::SingpleplayerMenuSDLViewModel::SingpleplayerMenuSDLViewModel(const Translate::TranslateEngine* Translation)
        : SingleplayerMenuAbstractViewModel(Translation)
{ }

std::string ViewModel::SingpleplayerMenuSDLViewModel::NameOfPlayer()
{
    //TODO
    return "";
}

int ViewModel::SingpleplayerMenuSDLViewModel::CountOfAI(int Max)
{
    //TODO
    return 0;
}

string ViewModel::SingpleplayerMenuSDLViewModel::Level()
{
    //TODO
    return 0;
}

string ViewModel::SingpleplayerMenuSDLViewModel::LevelOfAI(vector<string> MenuEntries)
{
    return 0;
}


#endif

