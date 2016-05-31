#include "SettingsSDLViewModel.h"
#ifdef USE_SDL

int ViewModel::SettingsSDLViewModel::ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const
{
    //TODO
    return 0;
}

ViewModel::SettingsSDLViewModel::SettingsSDLViewModel(const Translate::TranslateEngine* Translation)
        : SettingsAbstractViewModel(Translation)
{ }

void ViewModel::SettingsSDLViewModel::ShowActualLanguage() const
{
    //TODO
}

void ViewModel::SettingsSDLViewModel::ShowKeySettings() const
{

}

map<Game::Keys, Game::Actions> ViewModel::SettingsSDLViewModel::CreateNewSetting()
{
    using namespace Game;
    return std::map<Keys, Actions>();
}

void ViewModel::SettingsSDLViewModel::NotAbleToSetSettings(Game::Keys K)
{

}


#endif
