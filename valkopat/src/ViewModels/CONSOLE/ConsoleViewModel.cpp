#ifdef USE_CONSOLE
#include "ConsoleViewModel.h"

const char* ViewModel::ConsoleViewModel::GetNameofViewModel()
{
    return "Console";
}

void ViewModel::ConsoleViewModel::init(const Translate::TranslateEngine* Translate)
{
    SplashScren = new SplashScreenConsoleViewModel(Translate);
    Menu = new MenuConsoleViewModel(Translate);
    Language = new LanguageConsoleViewModel(Translate);
    Multiplayer = new MultiplayerConsoleViewModel(Translate);
    NetMenu = new NetMenuConsoleViewModel(Translate);
    Singpleplayer = new SingpleplayerMenuConsoleViewModel(Translate);
    Game = new GameConsoleViewModel(Translate);
    Score = new ScoreConsoleViewModel(Translate);
}

ViewModel::SplashScreenAbstractViewModel* ViewModel::ConsoleViewModel::SplashScreenModel()
{
    return this->SplashScren;
}

ViewModel::MenuAbstractViewModel* ViewModel::ConsoleViewModel::MenuModel()
{
    return this->Menu;
}

ViewModel::LanguageAbstractViewModel* ViewModel::ConsoleViewModel::LanguageModel()
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

ViewModel::ConsoleViewModel::~ConsoleViewModel()
{
    delete SplashScren;
    delete Menu;
    delete Language;
    delete Multiplayer;
    delete NetMenu;
    delete Singpleplayer;
    delete Game;
    delete Score;
}


#endif



