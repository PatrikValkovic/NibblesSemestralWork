#ifndef CERVISEMESTRALKA_MENUNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_MENUNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include <vector>
#include "../Abstract/MenuAbstractViewModel.h"

namespace ViewModel
{
    class MenuNCursesViewModel : public MenuAbstractViewModel
    {
    public:
        virtual int ShowMenu(std::vector<MenuEntry>);
    };
}
#endif
#endif //CERVISEMESTRALKA_MENUNCURSESVIEWMODEL_H
