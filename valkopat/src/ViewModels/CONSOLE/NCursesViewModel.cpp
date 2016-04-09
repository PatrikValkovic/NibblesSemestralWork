#ifdef USE_CONSOLE
#include "ConsoleViewModel.h"

const char* ViewModel::ConsoleViewModel::GetNameofViewModel()
{
    return "Console";
}

void ViewModel::ConsoleViewModel::init()
{
    //TODO
}

ViewModel::SplashScreenAbstractViewModel* ViewModel::ConsoleViewModel::SplashScreenModel()
{
    //TODO
    return nullptr;
}

ViewModel::MenuAbstractViewModel* ViewModel::ConsoleViewModel::MenuModel()
{
    //TODO
    return nullptr;
}

ViewModel::LanguageAbstractViewModel* ViewModel::ConsoleViewModel::LanguageModel()
{
    //TODO
    return nullptr;
}

ViewModel::MultiplayerMenuAbstractViewModel* ViewModel::ConsoleViewModel::MultiplayerModel()
{
    //TODO
    return nullptr;
}

ViewModel::NetMenuAbstractViewModel* ViewModel::ConsoleViewModel::NetModel()
{
    //TODO
    return nullptr;
}

ViewModel::SingleplayerMenuAbstractViewModel* ViewModel::ConsoleViewModel::SingleplayerModel()
{
    //TODO
    return nullptr;
}

ViewModel::GameAbstractViewModel* ViewModel::ConsoleViewModel::GameModel()
{
    //TODO
    return nullptr;
}

ViewModel::ScoreAbstractViewModel* ViewModel::ConsoleViewModel::ScoreModel()
{
    //TODO
    return nullptr;
}


#endif



