#ifndef CERVISEMESTRALKA_MENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_MENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <climits>
#include <vector>
#include <iostream>
#include "../Abstract/MenuAbstractViewModel.h"

namespace ViewModel
{
    class MenuConsoleViewModel : public MenuAbstractViewModel
    {
    public:
        MenuConsoleViewModel(const Translate::TranslateEngine* Translate);
        virtual int ShowMenu(std::vector<MenuEntry>);
    };
}
#endif
#endif //CERVISEMESTRALKA_MENUCONSOLEVIEWMODEL_H
