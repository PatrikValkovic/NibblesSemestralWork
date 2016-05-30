#ifdef USE_CONSOLE
#include "SplashPauseScreenConsoleViewModel.h"

void ViewModel::SplashPauseScreenConsoleViewModel::ShowSplashScreen()
{
    using namespace std;
    cout << this->Translation->GetTranslation("WhoMakeIt") << endl;
    cout << this->Translation->GetTranslation("DateOfCreation") << endl;
    cout << this->Translation->GetTranslation("HightSchool") << endl;
    cout << this->Translation->GetTranslation("Faculty") << endl;
}

ViewModel::SplashPauseScreenConsoleViewModel::SplashPauseScreenConsoleViewModel(const Translate::TranslateEngine* Translate)
        : SplashPauseScreenAbstractViewModel(Translate)
{ }

int ViewModel::SplashPauseScreenConsoleViewModel::ShowPauseWithMenu(std::map<int, string> MenuEntry)
{
    using namespace std;
    cout << Translation->GetTranslation("PauseHeading") << endl;
    map<int,pair<int,string>> Menu;
    int indexer = 1;

    //prepare it
    for_each(MenuEntry.begin(),MenuEntry.end(),[&Menu,&indexer](pair<int,string> X){
        Menu.insert(pair<int,pair<int,string>>(indexer++,X));
    });

    //render it
    while(true)
    {
        for_each(Menu.begin(),Menu.end(),[this](pair<int,pair<int,string>> Write){
            cout << Write.first << ": " << Translation->GetTranslation(Write.second.second) << endl;
        });
        cout << Translation->GetTranslation("ChoiceFromUser") << ':';
        int Choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cin >> Choice;
        try
        {
            return Menu.at(Choice).first;
        }
        catch(out_of_range e)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
        }

    }
}


#endif

