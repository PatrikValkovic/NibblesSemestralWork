#include "MenuConsoleViewModel.h"
#ifdef USE_CONSOLE
int ViewModel::MenuConsoleViewModel::ShowMenu(std::vector<ViewModel::MenuAbstractViewModel::MenuEntry>)
{
    using namespace std;
    cout << "Menu view model" << endl;
    //TODO
    return 0;
}

ViewModel::MenuConsoleViewModel::MenuConsoleViewModel(const Translate::TranslateEngine* Translate)
        : MenuAbstractViewModel(Translate)
{ }


#endif
