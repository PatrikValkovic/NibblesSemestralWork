#ifdef USE_NCURSES
#include "SingleplayerMenuNCursesViewModel.h"


ViewModel::SingleplayerMenuNCursesViewModel::SingleplayerMenuNCursesViewModel(
        const Translate::TranslateEngine* Translation)
        : SingleplayerMenuAbstractViewModel(Translation)
{ }

std::string ViewModel::SingleplayerMenuNCursesViewModel::NameOfPlayer()
{
    //TODO
    return "";
}

int ViewModel::SingleplayerMenuNCursesViewModel::CountOfAI(int Max)
{
    //TODO
    return 0;
}

string ViewModel::SingleplayerMenuNCursesViewModel::Level()
{
    //TODO
    return 0;
}

string ViewModel::SingleplayerMenuNCursesViewModel::LevelOfAI(std::vector<string> MenuEntries)
{
    return 0;
}


#endif

