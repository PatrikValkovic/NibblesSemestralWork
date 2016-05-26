#ifdef USE_CONSOLE
#include "ConsoleViewModel.h"

const char* ViewModel::ConsoleViewModel::GetNameofViewModel()
{
    return "Console";
}

void ViewModel::ConsoleViewModel::init(const Translate::TranslateEngine* Translate)
{
    SplashScren = new SplashPauseScreenConsoleViewModel(Translate);
    Menu = new MenuConsoleViewModel(Translate);
    Language = new SettingsConsoleViewModel(Translate);
    Multiplayer = new MultiplayerConsoleViewModel(Translate);
    NetMenu = new NetMenuConsoleViewModel(Translate);
    Singpleplayer = new SingpleplayerMenuConsoleViewModel(Translate);
    Game = new GameConsoleViewModel(Translate);
    Score = new ScoreConsoleViewModel(Translate);
    Quit = new QuitConsoleViewModel(Translate);
    Input = new ConsoleInput();
}

ViewModel::SplashPauseScreenAbstractViewModel* ViewModel::ConsoleViewModel::SplashPauseScreenModel()
{
    return this->SplashScren;
}

ViewModel::MenuAbstractViewModel* ViewModel::ConsoleViewModel::MenuModel()
{
    return this->Menu;
}

ViewModel::SettingsAbstractViewModel* ViewModel::ConsoleViewModel::LanguageModel()
{
    return this->Language;
}

ViewModel::MultiplayerMenuAbstractViewModel* ViewModel::ConsoleViewModel::MultiplayerModel()
{
    return this->Multiplayer;
}

ViewModel::NetMenuAbstractViewModel* ViewModel::ConsoleViewModel::NetModel()
{
    return this->NetMenu;
}

ViewModel::SingleplayerMenuAbstractViewModel* ViewModel::ConsoleViewModel::SingleplayerModel()
{
    return this->Singpleplayer;
}

ViewModel::GameAbstractViewModel* ViewModel::ConsoleViewModel::GameModel()
{
    return this->Game;
}

ViewModel::ScoreAbstractViewModel* ViewModel::ConsoleViewModel::ScoreModel()
{
    return this->Score;
}

ViewModel::QuitAbstractViewModel* ViewModel::ConsoleViewModel::QuitModel()
{
    return this->Quit;
}

ViewModel::AbstractInput* ViewModel::ConsoleViewModel::InputModel()
{
    return Input;
}



#endif



