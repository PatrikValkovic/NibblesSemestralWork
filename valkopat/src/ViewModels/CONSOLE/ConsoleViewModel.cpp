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

SplashScreenAbstractViewModel* ViewModel::ConsoleViewModel::SplashScreenModel()
{
    //TODO
    return nullptr;
}

MenuAbstractViewModel* ViewModel::ConsoleViewModel::MenuModel()
{
    //TODO
    return nullptr;
}

LanguageAbstractViewModel* ViewModel::ConsoleViewModel::LanguageModel()
{
    //TODO
    return nullptr;
}

MultiplayerMenuAbstractViewModel* ViewModel::ConsoleViewModel::MultiplayerModel()
{
    //TODO
    return nullptr;
}

NetMenuAbstractViewModel* ViewModel::ConsoleViewModel::NetModel()
{
    //TODO
    return nullptr;
}

SingleplayerMenuAbstractViewModel* ViewModel::ConsoleViewModel::SingleplayerModel()
{
    //TODO
    return nullptr;
}

GameAbstractViewModel* ViewModel::ConsoleViewModel::GameModel()
{
    //TODO
    return nullptr;
}

ScoreAbstractViewModel* ViewModel::ConsoleViewModel::ScoreModel()
{
    //TODO
    return nullptr;
}


#endif



