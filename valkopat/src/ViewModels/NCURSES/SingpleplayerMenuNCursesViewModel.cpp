#include "SingpleplayerMenuNCursesViewModel.h"
#ifdef USE_NCURSES

ViewModel::SingpleplayerMenuNCursesViewModel::SingpleplayerMenuNCursesViewModel(
        const Translate::TranslateEngine* Translation)
        : SingleplayerMenuAbstractViewModel(Translation)
{ }

std::string ViewModel::SingpleplayerMenuNCursesViewModel::NameOfPlayer()
{
    //TODO
    return "";
}

int ViewModel::SingpleplayerMenuNCursesViewModel::CountOfAI()
{
    //TODO
    return 0;
}

int ViewModel::SingpleplayerMenuNCursesViewModel::Level()
{
    //TODO
    return 0;
}


#endif

