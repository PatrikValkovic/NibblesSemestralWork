#ifdef USE_SDL
#include "SDLViewModel.h"

const char* ViewModel::SDLViewModel::GetNameofViewModel()
{
    return "SDL";
}

void ViewModel::SDLViewModel::init(const Translate::TranslateEngine* Translate)
{
    SplashScren = new SplashScreenSDLViewModel(Translate);
    Menu = new MenuSDLViewModel(Translate);
    Language = new SettingsSDLViewModel(Translate);
    Multiplayer = new MultiplayerSDLViewModel(Translate);
    NetMenu = new NetMenuSDLViewModel(Translate);
    Singpleplayer = new SingleplayerMenuSDLViewModel(Translate);
    Game = new GameSDLViewModel(Translate);
    Score = new ScoreSDLViewModel(Translate);
    Quit = new QuitSDLViewModel(Translate);
    Input = new SDLInput();
}

ViewModel::SplashPauseScreenAbstractViewModel* ViewModel::SDLViewModel::SplashPauseScreenModel()
{
    //TODO
    return NULL;
}

ViewModel::MenuAbstractViewModel* ViewModel::SDLViewModel::MenuModel()
{
    //TODO
    return NULL;
}

ViewModel::SettingsAbstractViewModel* ViewModel::SDLViewModel::LanguageModel()
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

ViewModel::QuitAbstractViewModel* ViewModel::SDLViewModel::QuitModel()
{
    //TODO
    return NULL;
}

ViewModel::AbstractInput* ViewModel::SDLViewModel::InputModel()
{
    //TODO
    return NULL;
}


#endif



