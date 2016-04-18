#ifndef CERVISEMESTRALKA_MENUSDLVIEWMODEL_H
#define CERVISEMESTRALKA_MENUSDLVIEWMODEL_H
#ifdef USE_SDL
#include <vector>
#include "../Abstract/MenuAbstractViewModel.h"

namespace ViewModel
{
    class MenuSDLViewModel : public MenuAbstractViewModel
    {
    public:
        MenuSDLViewModel(const Translate::TranslateEngine* Translation);
        virtual int ShowMenu(std::vector<MenuEntry>);
    };
}
#endif
#endif //CERVISEMESTRALKA_MENUSDLVIEWMODEL_H
