#ifndef CERVISEMESTRALKA_MENUABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_MENUABSTRACTVIEWMODEL_H
#include <string>
#include <vector>
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class MenuAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        MenuAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        struct MenuEntry
        {
            int index;
            std::string Text;
        };

        virtual ~MenuAbstractViewModel()
        { }

        virtual int ShowMenu(std::vector<MenuEntry>) = 0;
    };
}
#endif //CERVISEMESTRALKA_MENUABSTRACTVIEWMODEL_H
