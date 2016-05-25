#include "MultiplayerConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::MultiplayerConsoleViewModel::MultiplayerConsoleViewModel(const Translate::TranslateEngine* Translate)
        : MultiplayerMenuAbstractViewModel(Translate)
{ }

string ViewModel::MultiplayerConsoleViewModel::Level()
{
    using namespace std;
    int LevelIndex;
    const vector<string> Levels = Game::PlaygroundFactory::GetAviableLevels();
    while (true)
    {
        cout << Translation->GetTranslation("AviableLevels") << endl;
        int index = 1;
        for_each(Levels.begin(), Levels.end(), [&index, this](string i) {
            try
            {
                cout << index << ": " << Translation->GetTranslation(i) << endl;
            }
            catch (Exceptions::InvalidArgumentException* e)
            {
                delete e;
                cout << index << ": " << i << endl;
            }
            index++;
        });
        cout << Translation->GetTranslation("LevelChoose") << ':';
        cin >> LevelIndex;
        if (cin.fail() || LevelIndex < 1 || LevelIndex > (int) Levels.size())
            cout << Translation->GetTranslation("WrongEntry") << endl;
        else
            break;
    }
    return Levels.at((unsigned long) LevelIndex - 1);
}

int ViewModel::MultiplayerConsoleViewModel::CountOfPlayers(int Max)
{
    using namespace std;
    int CountOfPlayers = 1;
    while (true)
    {
        cout << Translation->GetTranslation("CountOfPlayers") << ':';
        cin >> CountOfPlayers;
        if (cin.fail() || CountOfPlayers > Max || CountOfPlayers < 0)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            cout << Translation->GetTranslation("MaxCount") << " " << Max << endl;
            continue;
        }
        break;
    }
    return CountOfPlayers;
}

string ViewModel::MultiplayerConsoleViewModel::NameOfPlayer(int Index)
{
    stringstream Stream;
    Stream << "NamePlayer" << Index;
    using namespace std;
    string Name;
    while (true)
    {
        cout << Translation->GetTranslation(Stream.str()) << ':';
        cin >> Name;
        if (cin.fail() || Name.length() == 0)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            continue;
        }
        break;
    }
    return Name;
}


#endif

