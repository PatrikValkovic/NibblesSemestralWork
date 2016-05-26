#include "SettingsState.h"

GameStates::SettingsState::SettingsState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::SettingsState::run()
{
    using ViewModel::SettingsAbstractViewModel;
    using ViewModel::SettingsConsoleViewModel;
    using namespace std;
    SettingsConsoleViewModel* Render = (SettingsConsoleViewModel*) this->RenderingModel->LanguageModel();
    map<string, string> Languages = Render->GetAviablesLanguages();
    map<int, SettingsAbstractViewModel::LanguageOverwiew> LanguagesEntries;
    map<int, string> AnotherEntries;
    int Index = 0;
    int Choose = 0;

    auto Moving = Languages.begin();
    auto End = Languages.end();
    for (; Moving != End; Moving++)
        LanguagesEntries.insert(pair<int, SettingsAbstractViewModel::LanguageOverwiew>
                                        (Index++,
                                         SettingsAbstractViewModel::LanguageOverwiew{Moving->first, Moving->second}));
    for (int a = 0; a < Game::Settings::GetInstance()->MaxCountOfPlayers(); a++)
        AnotherEntries.insert(pair<int, string>(Index++, "ChangeSettingForPlayer" + to_string(a + 1)));
    AnotherEntries.insert(pair<int, string>(999, "FromLanguageBackToMenu"));


    while (Choose != 999)
    {
        Render->ShowActualLanguage();
        Render->ShowKeySettings();
        Choose = Render->ShowMenu(LanguagesEntries, AnotherEntries);
        if (Choose != 999)
            Render->SetLanguage(LanguagesEntries.at(Choose).Shortcut);
    }
    return this->Menu;
}

void GameStates::SettingsState::AddStates(MenuGameState* MenuState)
{
    this->Menu = MenuState;
}





