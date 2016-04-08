#ifndef CERVISEMESTRALKA_MENUABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_MENUABSTRACTVIEWMODEL_H
#include <string>
#include <vector>


namespace ViewModel
{
    class MenuAbstractViewModel
    {
    public:
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
