#ifndef CERVISEMESTRALKA_NETMENUNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/NetMenuAbstractViewModel.h"

namespace ViewModel
{
    class NetMenuNCursesVIewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuNCursesVIewModel(const Translate::TranslateEngine* Translation);
    };
}

#endif
#endif //CERVISEMESTRALKA_NETMENUNCURSESVIEWMODEL_H
