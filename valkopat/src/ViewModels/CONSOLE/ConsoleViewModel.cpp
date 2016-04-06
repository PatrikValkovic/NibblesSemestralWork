#ifdef USE_CONSOLE
#include "ConsoleViewModel.h"

void ViewModel::ConsoleViewModel::ShowSplashScreen()
{
    using namespace std;
    cout << "Splash view pro konzolovou aplikaci" << endl;
    cin.get();
}

const char* ViewModel::ConsoleViewModel::GetNameofViewModel()
{
    return "Console";
}



#endif



