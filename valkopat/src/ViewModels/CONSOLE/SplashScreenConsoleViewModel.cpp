#ifdef USE_CONSOLE
#include "SplashScreenConsoleViewModel.h"

void ViewModel::SplashScreenConsoleViewModel::ShowSplashScreen()
{
    using namespace std;
    cout << this->Translation->GetTranslation("WhoMakeIt") << endl;
    cout << this->Translation->GetTranslation("DateOfCreation") << endl;
    cout << this->Translation->GetTranslation("HightSchool") << endl;
    cout << this->Translation->GetTranslation("Faculty") << endl;
}

ViewModel::SplashScreenConsoleViewModel::SplashScreenConsoleViewModel(const Translate::TranslateEngine* Translate)
        : SplashScreenAbstractViewModel(Translate)
{ }


#endif

