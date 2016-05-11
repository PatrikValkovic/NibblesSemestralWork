#include "SingpleplayerMenuConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::SingpleplayerMenuConsoleViewModel::SingpleplayerMenuConsoleViewModel(const Translate::TranslateEngine* Translate)
        : SingleplayerMenuAbstractViewModel(Translate)
{ }

int ViewModel::SingpleplayerMenuConsoleViewModel::CountOfAI(int Max)
{
    using namespace std;
    while(true)
    {
        cout << Translation->GetTranslation("CountOfAI") << ':';
        cin >> this->CountOfAIInGame;
        if (cin.fail() || this->CountOfAIInGame > Max || this->CountOfAIInGame<0)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            cout << Translation->GetTranslation("MaxCount") << " " << Max << endl;
            continue;
        }
        break;
    }
    return this->CountOfAIInGame;
}

std::string ViewModel::SingpleplayerMenuConsoleViewModel::NameOfPlayer()
{
    using namespace std;
    while(true)
    {
        cout << Translation->GetTranslation("ChooseName") << ':';
        cin >> this->Name;
        if (cin.fail() || this->Name.length() == 0)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            continue;
        }
        break;
    }
    return this->Name;
}

int ViewModel::SingpleplayerMenuConsoleViewModel::Level()
{
    using namespace std;
    const map<int, string> Levels = Game::PlaygroundFactory::GetCountOfAviableLevels();
    while(true)
    {
        cout << Translation->GetTranslation("AviableLevels") << endl;
        for_each(Levels.begin(),Levels.end(),[this](pair<int,string> i){
            cout << i.first << ": " << Translation->GetTranslation(i.second) << endl;
        });
        cout << Translation->GetTranslation("LevelChoose") << ':';
        cin >> this->LevelIndex;
        if(cin.fail() || Levels.find(this->LevelIndex)==Levels.end())
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            continue;
        }
        break;
    }
    return this->LevelIndex;
}

#endif


