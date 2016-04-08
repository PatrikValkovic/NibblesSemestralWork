#ifndef CERVISEMESTRALKA_MENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_MENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <vector>
#include "../Abstract/MenuAbstractViewModel.h"

namespace ViewModel
{
    class MenuConsoleViewModel : public MenuAbstractViewModel
    {
    public:
        virtual int ShowMenu(std::vector<MenuEntry>);
    };
}
#endif
#endif //CERVISEMESTRALKA_MENUCONSOLEVIEWMODEL_H