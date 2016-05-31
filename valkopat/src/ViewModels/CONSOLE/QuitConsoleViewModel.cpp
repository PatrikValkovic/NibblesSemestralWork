#include "QuitConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::QuitConsoleViewModel::QuitConsoleViewModel(const Translate::TranslateEngine* Translation)
    : QuitAbstractViewModel(Translation)
{}

void ViewModel::QuitConsoleViewModel::ShowEndScreen()
{
    using namespace std;
    cout << Translation->GetTranslation("WillBeExited") << endl;
    cout << Translation->GetTranslation("LastWord") << endl;
}


#endif



