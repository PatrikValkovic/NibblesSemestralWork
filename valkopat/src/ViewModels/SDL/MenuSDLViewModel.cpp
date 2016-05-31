#include "MenuSDLViewModel.h"
#ifdef USE_SDL

int ViewModel::MenuSDLViewModel::ShowMenu(std::vector<ViewModel::MenuAbstractViewModel::MenuEntry>)
{
    //TODO
    return 0;
}

ViewModel::MenuSDLViewModel::MenuSDLViewModel(const Translate::TranslateEngine* Translation)
        : MenuAbstractViewModel(Translation)
{ }


#endif
