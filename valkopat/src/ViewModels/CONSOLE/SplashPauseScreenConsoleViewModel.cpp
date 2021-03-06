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

ViewModel::SplashPauseScreenConsoleViewModel::SplashPauseScreenConsoleViewModel(
        const Translate::TranslateEngine* Translate)
        : SplashPauseScreenAbstractViewModel(Translate)
{ }

int ViewModel::SplashPauseScreenConsoleViewModel::ShowPauseWithMenu(std::map<int, string> MenuEntry)
{
    using namespace std;
    cout << Translation->GetTranslation("PauseHeading") << endl;
    map<int, pair<int, string>> Menu;
    int indexer = 1;

    //prepare it
    for_each(MenuEntry.begin(), MenuEntry.end(), [&Menu, &indexer](pair<int, string> X) {
        Menu.insert(pair<int, pair<int, string>>(indexer++, X));
    });

    int Choice;
    cin.clear();

    while (true)
    {
        for_each(Menu.begin(), Menu.end(), [this](pair<int, pair<int, string>> Write) {
            cout << Write.first << ": " << Translation->GetTranslation(Write.second.second) << endl;
        });
        cout << Translation->GetTranslation("ChoiceFromUser") << ':';

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }

        cin >> Choice;

        try
        {
            return Menu.at(Choice).first;
        }
        catch (out_of_range e)
        {
            cout << Translation->GetTranslation("WrongEntry") << endl;
        }

    }
}

void ViewModel::SplashPauseScreenConsoleViewModel::ShowFinalScore(std::vector<Game::Worm*> Worms)
{
    using namespace std;
    using Game::Worm;
    cout << Translation->GetTranslation("Result") << endl;

    sort(Worms.begin(), Worms.end(), [](Worm* First, Worm* Second) {
        return First->GetSegment().size() > Second->GetSegment().size();
    });

    int Index = 1;
    for_each(Worms.begin(), Worms.end(), [&Index,this](Worm* W) {
        cout << Index++
                << ' '
                << W->GetName()
                << ' '
                << Translation->GetTranslation("WithScore")
                << ' '
                << W->GetSegment().size()
                << endl;
    });
}


#endif

