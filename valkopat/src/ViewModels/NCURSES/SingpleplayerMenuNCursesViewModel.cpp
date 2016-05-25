#ifdef USE_NCURSES
#include "SingpleplayerMenuNCursesViewModel.h"


ViewModel::SingpleplayerMenuNCursesViewModel::SingpleplayerMenuNCursesViewModel(
        const Translate::TranslateEngine* Translation)
        : SingleplayerMenuAbstractViewModel(Translation)
{ }

std::string ViewModel::SingpleplayerMenuNCursesViewModel::NameOfPlayer()
{
    //TODO
    return "";
}

int ViewModel::SingpleplayerMenuNCursesViewModel::CountOfAI(int Max)
{
    //TODO
    return 0;
}

string ViewModel::SingpleplayerMenuNCursesViewModel::Level()
{
    //TODO
    return 0;
}

string ViewModel::SingpleplayerMenuNCursesViewModel::LevelOfAI(std::vector<string> MenuEntries)
{
    return 0;
}


#endif

