#include "SettingsConsoleViewModel.h"
#ifdef USE_CONSOLE

int ViewModel::SettingsConsoleViewModel::ShowMenu(std::map<int, LanguageOverwiew> LanguagesToChoose,
                                                  std::map<int, string> Entries) const
{
    using namespace std;
    while (true)
    {
        map<int, int> Keys;
        int Index = 1;
        int UserChoice;
        for_each(LanguagesToChoose.begin(), LanguagesToChoose.end(),
                 [&Index, &Keys, this](pair<int, LanguageOverwiew> Input) {
                     cout << Index << ": " << this->Translation->GetTranslation("ChangeLanguageTo") << " "
                     << Input.second.Shortcut << '_' << Input.second.Name << endl;
                     Keys.insert(pair<int, int>(Index++, Input.first));
                 });

        for_each(Entries.begin(), Entries.end(), [&Index, &Keys, this](pair<int, string> Input) {
            cout << Index << ": " << this->Translation->GetTranslation(Input.second) << endl;
            Keys.insert(pair<int, int>(Index++, Input.first));
        });

        cout << Translation->GetTranslation("ChoiceFromUser") << ": ";
        cin >> UserChoice;

        if (!(cin) || Keys.find(UserChoice) == Keys.end())
        {
            cin.clear();
            cin.ignore();
            cout << Translation->GetTranslation("WrongEntry") << endl;
        }
        else
            return Keys.at(UserChoice);
    }
}

ViewModel::SettingsConsoleViewModel::SettingsConsoleViewModel(const Translate::TranslateEngine* Translate)
        : SettingsAbstractViewModel(Translate)
{ }

void ViewModel::SettingsConsoleViewModel::ShowActualLanguage() const
{
    using namespace std;
    cout << Translation->GetTranslation("LabelActualActivatedLanguage") << ": " << Translation->GetActualLanguage() <<
    endl;
}

void ViewModel::SettingsConsoleViewModel::ShowKeySettings() const
{
    using namespace std;
    using namespace Game;
    const static map<Actions, string> TranslateActions{
            pair<Actions, string>(Actions::MoveUp, "Up"),
            pair<Actions, string>(Actions::MoveDown, "Down"),
            pair<Actions, string>(Actions::MoveLeft, "Left"),
            pair<Actions, string>(Actions::MoveRight, "Right"),
            pair<Actions, string>(Actions::Pause, "Pause"),
    };
    static const std::map<Keys, char> KeyTranslate{
            std::pair<Game::Keys, char>(Game::Keys::KeyA, 'a'),
            std::pair<Game::Keys, char>(Game::Keys::KeyB, 'b'),
            std::pair<Game::Keys, char>(Game::Keys::KeyC, 'c'),
            std::pair<Game::Keys, char>(Game::Keys::KeyD, 'd'),
            std::pair<Game::Keys, char>(Game::Keys::KeyE, 'e'),
            std::pair<Game::Keys, char>(Game::Keys::KeyF, 'f'),
            std::pair<Game::Keys, char>(Game::Keys::KeyG, 'g'),
            std::pair<Game::Keys, char>(Game::Keys::KeyH, 'h'),
            std::pair<Game::Keys, char>(Game::Keys::KeyI, 'i'),
            std::pair<Game::Keys, char>(Game::Keys::KeyJ, 'j'),
            std::pair<Game::Keys, char>(Game::Keys::KeyK, 'k'),
            std::pair<Game::Keys, char>(Game::Keys::KeyL, 'l'),
            std::pair<Game::Keys, char>(Game::Keys::KeyM, 'm'),
            std::pair<Game::Keys, char>(Game::Keys::KeyN, 'n'),
            std::pair<Game::Keys, char>(Game::Keys::KeyO, 'o'),
            std::pair<Game::Keys, char>(Game::Keys::KeyP, 'p'),
            std::pair<Game::Keys, char>(Game::Keys::KeyQ, 'q'),
            std::pair<Game::Keys, char>(Game::Keys::KeyR, 'r'),
            std::pair<Game::Keys, char>(Game::Keys::KeyS, 's'),
            std::pair<Game::Keys, char>(Game::Keys::KeyT, 't'),
            std::pair<Game::Keys, char>(Game::Keys::KeyU, 'u'),
            std::pair<Game::Keys, char>(Game::Keys::KeyV, 'v'),
            std::pair<Game::Keys, char>(Game::Keys::KeyW, 'w'),
            std::pair<Game::Keys, char>(Game::Keys::KeyX, 'x'),
            std::pair<Game::Keys, char>(Game::Keys::KeyY, 'y'),
            std::pair<Game::Keys, char>(Game::Keys::KeyZ, 'z'),
            std::pair<Game::Keys, char>(Game::Keys::Key0, '0'),
            std::pair<Game::Keys, char>(Game::Keys::Key1, '1'),
            std::pair<Game::Keys, char>(Game::Keys::Key2, '2'),
            std::pair<Game::Keys, char>(Game::Keys::Key3, '3'),
            std::pair<Game::Keys, char>(Game::Keys::Key4, '4'),
            std::pair<Game::Keys, char>(Game::Keys::Key5, '5'),
            std::pair<Game::Keys, char>(Game::Keys::Key6, '6'),
            std::pair<Game::Keys, char>(Game::Keys::Key7, '7'),
            std::pair<Game::Keys, char>(Game::Keys::Key8, '8'),
            std::pair<Game::Keys, char>(Game::Keys::Key9, '9'),
    };

    for (int a = 0; a < Settings::GetInstance()->MaxCountOfPlayers(); a++)
    {
        map<Keys, Actions> SettingForPlayer = Settings::GetInstance()->GetSettingForPlayer(a);
        cout << Translation->GetTranslation("SettingsForPlayer") << ' ' << a+1 << endl;
        for_each(SettingForPlayer.begin(), SettingForPlayer.end(), [this]
                (pair<Keys, Actions> P)
        {
            cout << '\t' << Translation->GetTranslation(TranslateActions.at(P.second))
            << '\t' << KeyTranslate.at(P.first) << endl;
        });
    }
}


#endif
