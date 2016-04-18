#ifdef USE_NCURSES
#include "NCursesViewModel.h"

const char* ViewModel::NCursesViewModel::GetNameofViewModel()
{
    return "NCurses";
}

void ViewModel::NCursesViewModel::init(const Translate::TranslateEngine* Translate)
{
    //TODO
}

ViewModel::SplashScreenAbstractViewModel* ViewModel::NCursesViewModel::SplashScreenModel()
{
    //TODO
    return NULL;
}

ViewModel::MenuAbstractViewModel* ViewModel::NCursesViewModel::MenuModel()
{
    //TODO
    return NULL;
}

ViewModel::LanguageAbstractViewModel* ViewModel::NCursesViewModel::LanguageModel()
{
    //TODO
    return NULL;
}

ViewModel::MultiplayerMenuAbstractViewModel* ViewModel::NCursesViewModel::MultiplayerModel()
{
    //TODO
    return NULL;
}

ViewModel::NetMenuAbstractViewModel* ViewModel::NCursesViewModel::NetModel()
{
    //TODO
    return NULL;
}

ViewModel::SingleplayerMenuAbstractViewModel* ViewModel::NCursesViewModel::SingleplayerModel()
{
    //TODO
    return NULL;
}

ViewModel::GameAbstractViewModel* ViewModel::NCursesViewModel::GameModel()
{
    //TODO
    return NULL;
}

ViewModel::ScoreAbstractViewModel* ViewModel::NCursesViewModel::ScoreModel()
{
    //TODO
    return NULL;
}


#endif



