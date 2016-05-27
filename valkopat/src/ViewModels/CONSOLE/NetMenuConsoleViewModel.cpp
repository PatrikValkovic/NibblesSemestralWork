#include "NetMenuConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::NetMenuConsoleViewModel::NetMenuConsoleViewModel(const Translate::TranslateEngine* Translate)
        : NetMenuAbstractViewModel(Translate)
{ }

string ViewModel::NetMenuConsoleViewModel::Level()
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

int ViewModel::NetMenuConsoleViewModel::CountOfPlayers(int Max)
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

pair<string, string> ViewModel::NetMenuConsoleViewModel::GetIPAndPort()
{
    using namespace std;
    pair<string,string> Attrs;
    while (true)
    {
        cout << Translation->GetTranslation("ServerIPPort") << endl;
        string Text;
        cin >> Text;
        if (cin.fail())
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            continue;
        }

        unsigned long LastIndexOfColon = Text.find_last_of(':');
        Attrs.first = Text.substr(0,LastIndexOfColon);
        Attrs.second = Text.substr(LastIndexOfColon+1);
        return Attrs;
    }
}

bool ViewModel::NetMenuConsoleViewModel::CreateNewServer()
{
    while (true)
    {
        cout << Translation->GetTranslation("ChooseMode") << endl;
        cout << "1:" << Translation->GetTranslation("CreateNewServer") << endl;
        cout << "2:" << Translation->GetTranslation("ConnectToServer") << endl;
        cout << Translation->GetTranslation("ChoiceFromUser") << ':';
        int Choice;
        cin >> Choice;
        if (cin.fail() || Choice < 1 || Choice > 2)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            continue;
        }
        return Choice == 1;
    }
}

void ViewModel::NetMenuConsoleViewModel::ServerCreated()
{
    cout << Translation->GetTranslation("ServerCreated") << endl;
}

void ViewModel::NetMenuConsoleViewModel::ServerNotCreated()
{
    cout << Translation->GetTranslation("ServerNotCreated") << endl;
}

void ViewModel::NetMenuConsoleViewModel::CreatingAndConnectingError()
{
    cout << Translation->GetTranslation("ErrorWhenCreatingAndConnectiong") << endl;
}

void ViewModel::NetMenuConsoleViewModel::CannotConnect()
{
    cout << Translation->GetTranslation("CannotConnect") << endl;
}

void ViewModel::NetMenuConsoleViewModel::ServerNotRespond()
{
    cout << Translation->GetTranslation("ServerNotRespond") << endl;
}

void ViewModel::NetMenuConsoleViewModel::ServerRespond()
{
    cout << Translation->GetTranslation("ServerRespond") << endl;
}


#endif


