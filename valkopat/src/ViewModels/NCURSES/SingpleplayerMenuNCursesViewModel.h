#ifndef CERVISEMESTRALKA_SINGPLEPLAYERMENUNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERMENUNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/SingpleplayerAbstractViewModel.h"
namespace ViewModel
{
    class SingpleplayerMenuNCursesViewModel : public SingleplayerMenuAbstractViewModel
    {
    public:
        SingpleplayerMenuNCursesViewModel(const Translate::TranslateEngine* Translation);
    };
}
#endif
#endif //CERVISEMESTRALKA_SINGPLEPLAYERMENUNCURSESVIEWMODEL_H
