#include "SettingsConsoleViewModel.h"
#ifdef USE_CONSOLE

const map<Game::Actions, std::string>
        ViewModel::SettingsConsoleViewModel::TranslateActions{
        pair<Game::Actions, string>(Game::Actions::MoveUp, "Up"),
        pair<Game::Actions, string>(Game::Actions::MoveDown, "Down"),
        pair<Game::Actions, string>(Game::Actions::MoveLeft, "Left"),
        pair<Game::Actions, string>(Game::Actions::MoveRight, "Right"),
        pair<Game::Actions, string>(Game::Actions::Pause, "Pause"),
};
const std::map<Game::Keys, char>
        ViewModel::SettingsConsoleViewModel::KeyTranslate{
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
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> UserChoice;

        if (!(cin) || Keys.find(UserChoice) == Keys.end())
            cout << Translation->GetTranslation("WrongEntry") << endl;
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
    cout << Translation->GetTranslation("LabelActualActivatedLanguage")
            << ": "
            << Translation->GetActualLanguage()
            << endl;
}

void ViewModel::SettingsConsoleViewModel::ShowKeySettings() const
{
    using namespace std;
    using namespace Game;

    for (int a = 0; a < Settings::GetInstance()->MaxCountOfPlayers(); a++)
    {
        map<Keys, Actions> SettingForPlayer = Settings::GetInstance()->GetSettingForPlayer(a);
        cout << Translation->GetTranslation("SettingsForPlayer") << ' ' << a + 1 << endl;
        for_each(SettingForPlayer.begin(), SettingForPlayer.end(), [this]
                (pair<Keys, Actions> P) {
            cout << '\t' << Translation->GetTranslation(TranslateActions.at(P.second))
            << '\t' << KeyTranslate.at(P.first) << endl;
        });
    }
}

map<Game::Keys, Game::Actions> ViewModel::SettingsConsoleViewModel::CreateNewSetting()
{
    using namespace std;
    using namespace Game;
    map<Keys, Actions> ToReturn;
    vector<Actions> ActionsToChange{MoveUp, MoveDown, MoveLeft, MoveRight, Pause};

    this->ClearInput();

    for (int a = 0; a < (int) ActionsToChange.size(); a++)
        while (true)
        {
            cout << Translation->GetTranslation("PushKeyToChange")
            << ':'
            << Translation->GetTranslation(TranslateActions.at(ActionsToChange.at(a)))
            << ' '
            << Translation->GetTranslation("EnterToDontChange")
            << ':';
            char Readed;
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cin.get(Readed);
            if (Readed == '\n')
                break;

            map<Keys, char>::const_iterator Finding = find_if(KeyTranslate.begin(), KeyTranslate.end(), [&Readed]
                    (pair<Keys, char> P) {
                return P.second == Readed;
            });
            if (Finding == KeyTranslate.end())
            {
                cout << Translation->GetTranslation("WrongEntry") << endl;
                continue;
            }
            ToReturn.insert(pair<Keys, Actions>(Finding->first, ActionsToChange.at(a)));
            break;
        }

    return ToReturn;
}

void ViewModel::SettingsConsoleViewModel::ClearInput()
{
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}

void ViewModel::SettingsConsoleViewModel::NotAbleToSetSettings(Game::Keys K)
{
    cout << Translation->GetTranslation("NotAbleToApplySetting") << " " << KeyTranslate.at(K) << endl;
}


#endif
