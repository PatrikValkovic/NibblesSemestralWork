#ifndef CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/SingpleplayerAbstractViewModel.h"
namespace ViewModel
{
    class SingpleplayerMenuConsoleViewModel : public SingleplayerMenuAbstractViewModel
    {
    public:
        SingpleplayerMenuConsoleViewModel(const Translate::TranslateEngine* Translate);
    };
}
#endif
#endif //CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
