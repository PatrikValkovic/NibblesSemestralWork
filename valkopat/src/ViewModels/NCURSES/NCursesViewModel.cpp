#ifdef USE_NCURSES
#include "NCursesViewModel.h"

const char* ViewModel::NCursesViewModel::GetNameofViewModel()
{
    return "NCurses";
}

void ViewModel::NCursesViewModel::init(const Translate::TranslateEngine* Translate)
{
    SplashScren = new SplashScreenNCursesViewModel(Translate);
    Menu = new MenuNCursesViewModel(Translate);
    Language = new SettingsNCursesViewModel(Translate);
    Multiplayer = new MultiplayerNCursesViewModel(Translate);
    NetMenu = new NetMenuNCursesVIewModel(Translate);
    Singpleplayer = new SingpleplayerMenuNCursesViewModel(Translate);
    Game = new GameNCursesViewModel(Translate);
    Score = new ScoreNCursesViewModel(Translate);
    Quit = new QuitNCursesViewModel(Translate);
    Input = new NCursesInput();
}

ViewModel::SplashPauseScreenAbstractViewModel* ViewModel::NCursesViewModel::SplashPauseScreenModel()
{
    //TODO
    return NULL;
}

ViewModel::MenuAbstractViewModel* ViewModel::NCursesViewModel::MenuModel()
{
    //TODO
    return NULL;
}

ViewModel::SettingsAbstractViewModel* ViewModel::NCursesViewModel::LanguageModel()
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

ViewModel::QuitAbstractViewModel* ViewModel::NCursesViewModel::QuitModel()
{
    //TODO
    return NULL;
}

ViewModel::AbstractInput* ViewModel::NCursesViewModel::InputModel()
{
    //TODO
    return NULL;
}


#endif



