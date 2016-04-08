#ifdef USE_SDL
#include "SDLViewModel.h"

const char* ViewModel::SDLViewModel::GetNameofViewModel()
{
    return "SDL";
}

void ViewModel::SDLViewModel::init()
{
    //TODO
}

ViewModel::SplashScreenAbstractViewModel* ViewModel::SDLViewModel::SplashScreenModel()
{
    //TODO
    return nullptr;
}

ViewModel::MenuAbstractViewModel* ViewModel::SDLViewModel::MenuModel()
{
    //TODO
    return nullptr;
}

ViewModel::LanguageAbstractViewModel* ViewModel::SDLViewModel::LanguageModel()
{
    //TODO
    return nullptr;
}

ViewModel::MultiplayerMenuAbstractViewModel* ViewModel::SDLViewModel::MultiplayerModel()
{
    //TODO
    return nullptr;
}

ViewModel::NetMenuAbstractViewModel* ViewModel::SDLViewModel::NetModel()
{
    //TODO
    return nullptr;
}

ViewModel::SingleplayerMenuAbstractViewModel* ViewModel::SDLViewModel::SingleplayerModel()
{
    //TODO
    return nullptr;
}

ViewModel::GameAbstractViewModel* ViewModel::SDLViewModel::GameModel()
{
    //TODO
    return nullptr;
}

ViewModel::ScoreAbstractViewModel* ViewModel::SDLViewModel::ScoreModel()
{
    //TODO
    return nullptr;
}


#endif



