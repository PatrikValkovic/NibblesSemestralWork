#ifdef USE_SDL
#include "SDLViewModel.h"

const char* ViewModel::SDLViewModel::GetNameofViewModel()
{
    return "SDL";
}

void ViewModel::SDLViewModel::init(const Translate::TranslateEngine* Translate)
{
    //TODO
}

ViewModel::SplashScreenAbstractViewModel* ViewModel::SDLViewModel::SplashScreenModel()
{
    //TODO
    return NULL;
}

ViewModel::MenuAbstractViewModel* ViewModel::SDLViewModel::MenuModel()
{
    //TODO
    return NULL;
}

ViewModel::LanguageAbstractViewModel* ViewModel::SDLViewModel::LanguageModel()
{
    //TODO
    return NULL;
}

ViewModel::MultiplayerMenuAbstractViewModel* ViewModel::SDLViewModel::MultiplayerModel()
{
    //TODO
    return NULL;
}

ViewModel::NetMenuAbstractViewModel* ViewModel::SDLViewModel::NetModel()
{
    //TODO
    return NULL;
}

ViewModel::SingleplayerMenuAbstractViewModel* ViewModel::SDLViewModel::SingleplayerModel()
{
    //TODO
    return NULL;
}

ViewModel::GameAbstractViewModel* ViewModel::SDLViewModel::GameModel()
{
    //TODO
    return NULL;
}

ViewModel::ScoreAbstractViewModel* ViewModel::SDLViewModel::ScoreModel()
{
    //TODO
    return NULL;
}


#endif



