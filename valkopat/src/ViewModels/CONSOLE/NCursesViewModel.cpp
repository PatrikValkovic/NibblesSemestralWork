#ifdef USE_CONSOLE
#include "ConsoleViewModel.h"

const char* ViewModel::NCursesViewModel::GetNameofViewModel()
{
    return "Console";
}

void ViewModel::NCursesViewModel::init()
{
    //TODO
}

ViewModel::SplashScreenAbstractViewModel* ViewModel::NCursesViewModel::SplashScreenModel()
{
    //TODO
    return nullptr;
}

ViewModel::MenuAbstractViewModel* ViewModel::NCursesViewModel::MenuModel()
{
    //TODO
    return nullptr;
}

ViewModel::LanguageAbstractViewModel* ViewModel::NCursesViewModel::LanguageModel()
{
    //TODO
    return nullptr;
}

ViewModel::MultiplayerMenuAbstractViewModel* ViewModel::NCursesViewModel::MultiplayerModel()
{
    //TODO
    return nullptr;
}

ViewModel::NetMenuAbstractViewModel* ViewModel::NCursesViewModel::NetModel()
{
    //TODO
    return nullptr;
}

ViewModel::SingleplayerMenuAbstractViewModel* ViewModel::NCursesViewModel::SingleplayerModel()
{
    //TODO
    return nullptr;
}

ViewModel::GameAbstractViewModel* ViewModel::NCursesViewModel::GameModel()
{
    //TODO
    return nullptr;
}

ViewModel::ScoreAbstractViewModel* ViewModel::NCursesViewModel::ScoreModel()
{
    //TODO
    return nullptr;
}


#endif



