#include "SettingsState.h"

GameStates::SettingsState::SettingsState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::SettingsState::run()
{
    using ViewModel::SettingsAbstractViewModel;
    using namespace std;
    SettingsAbstractViewModel* Render = this->RenderingModel->LanguageModel();
    map<string, string> Languages = Render->GetAviablesLanguages();
    map<int, SettingsAbstractViewModel::LanguageOverwiew> LanguagesEntries;
    map<int, string> AnotherEntries;
    int Index = 0;
    int Choose = 0;

    auto Moving = Languages.begin();
    auto End = Languages.end();
    for(;Moving!=End;Moving++)
        LanguagesEntries.insert(pair<int,SettingsAbstractViewModel::LanguageOverwiew>
                        (Index++,SettingsAbstractViewModel::LanguageOverwiew{Moving->first,Moving->second}));
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

void GameStates::SettingsState::AddStates(MenuGameState* MenuState)
{
    this->Menu = MenuState;
}





