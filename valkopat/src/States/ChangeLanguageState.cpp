#include "ChangeLanguageState.h"

GameState::ChangeLanguageState::ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameState::AbstractGameState* GameState::ChangeLanguageState::run()
{
    using ViewModel::LanguageAbstractViewModel;
    using namespace std;
    LanguageAbstractViewModel* Render = this->RenderingModel->LanguageModel();
    map<string, string> Languages = Render->GetAviablesLanguages();
    map<int, LanguageAbstractViewModel::LanguageOverwiew> LanguagesEntries;
    map<int, string> AnotherEntries;
    int Index = 0;
    int Choose = 0;

    auto Moving = Languages.begin();
    auto End = Languages.end();
    for(;Moving!=End;Moving++)
        LanguagesEntries.insert(pair<int,LanguageAbstractViewModel::LanguageOverwiew>
                        (Index++,(LanguageAbstractViewModel::LanguageOverwiew){Moving->first,Moving->second}));
    AnotherEntries.insert(pair<int, string>(-1, "FromLanguageBackToMenu"));


    while (Choose != -1)
    {
        Render->ShowInfo();
        int Choose = Render->ShowMenu(LanguagesEntries, AnotherEntries);
        if (Choose == -1)
            break;
        Render->SetLanguage(LanguagesEntries.at(Choose).Shortcut);
    }
    return this->Menu;
}

void GameState::ChangeLanguageState::AddStates(MenuGameState* MenuState)
{
    this->Menu = MenuState;
}





