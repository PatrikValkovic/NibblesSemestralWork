#ifdef USE_SDL
#include "SingleplayerMenuSDLViewModel.h"


ViewModel::SingleplayerMenuSDLViewModel::SingleplayerMenuSDLViewModel(const Translate::TranslateEngine* Translation)
        : SingleplayerMenuAbstractViewModel(Translation)
{ }

std::string ViewModel::SingleplayerMenuSDLViewModel::NameOfPlayer()
{
    //TODO
    return "";
}

int ViewModel::SingleplayerMenuSDLViewModel::CountOfAI(int Max)
{
    //TODO
    return 0;
}

string ViewModel::SingleplayerMenuSDLViewModel::Level()
{
    //TODO
    return 0;
}

string ViewModel::SingleplayerMenuSDLViewModel::LevelOfAI(vector<string> MenuEntries)
{
    return 0;
}


#endif

