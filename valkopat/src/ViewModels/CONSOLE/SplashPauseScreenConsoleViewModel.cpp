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
    //TODO
    return 0;
}


#endif

