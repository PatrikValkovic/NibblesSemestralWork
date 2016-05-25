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

string ViewModel::SingpleplayerMenuConsoleViewModel::Level()
{
    using namespace std;
    const vector<string> Levels = Game::PlaygroundFactory::GetAviableLevels();
    while(true)
    {
        cout << Translation->GetTranslation("AviableLevels") << endl;
        int index = 1;
        for_each(Levels.begin(),Levels.end(),[&index,this](string i){
            try
            {
                cout << index << ": " << Translation->GetTranslation(i) << endl;
            }
            catch(Exceptions::InvalidArgumentException* e)
            {
                delete e;
                cout << index << ": " << i << endl;
            }
            index++;
        });
        cout << Translation->GetTranslation("LevelChoose") << ':';
        cin >> this->LevelIndex;
        if(cin.fail() || this->LevelIndex<1 || this->LevelIndex>(int)Levels.size())
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
            continue;
        }
        break;
    }
    return Levels.at(this->LevelIndex-1);
}

string ViewModel::SingpleplayerMenuConsoleViewModel::LevelOfAI(std::vector<string> MenuEntries)
{
    return 0;
}


#endif


