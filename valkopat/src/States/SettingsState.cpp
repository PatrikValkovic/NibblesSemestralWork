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
    map<int, int> MenuEntryAnPlayerIndex;
    int Index = 0;
    int Choose = 0;

    auto Moving = Languages.begin();
    auto End = Languages.end();
    for (; Moving != End; Moving++)
        LanguagesEntries.insert(pair<int, SettingsAbstractViewModel::LanguageOverwiew>
                                        (Index++,
                                         SettingsAbstractViewModel::LanguageOverwiew{Moving->first, Moving->second}));
    for (int a = 0; a < Game::Settings::GetInstance()->MaxCountOfPlayers(); a++)
    {
        AnotherEntries.insert(pair<int, string>(Index, "ChangeSettingForPlayer" + to_string(a + 1)));
        MenuEntryAnPlayerIndex.insert(pair<int, int>(Index++, a));
    }
    AnotherEntries.insert(pair<int, string>(999, "FromLanguageBackToMenu"));


    while (Choose != 999)
    {
        Render->ShowActualLanguage();
        Render->ShowKeySettings();
        Choose = Render->ShowMenu(LanguagesEntries, AnotherEntries);
        if (LanguagesEntries.find(Choose) != LanguagesEntries.end())
            Render->SetLanguage(LanguagesEntries.at(Choose).Shortcut);
        if (AnotherEntries.find(Choose) != AnotherEntries.end() && Choose != 999)
        {
            map<Game::Keys, Game::Actions> NewSetting = Render->CreateNewSetting();
            for_each(NewSetting.begin(), NewSetting.end(),
                     [&Choose, &MenuEntryAnPlayerIndex,&Render](pair<Game::Keys, Game::Actions> P) {
                         if (!Game::Settings::GetInstance()->SetAction(P.first,
                                                                       MenuEntryAnPlayerIndex.at(Choose),
                                                                       P.second))
                             Render->NotAbleToSetSettings(P.first);
                     });
        }
    }
    return this->Menu;
}

void GameStates::SettingsState::AddStates(MenuGameState* MenuState)
{
    this->Menu = MenuState;
}





