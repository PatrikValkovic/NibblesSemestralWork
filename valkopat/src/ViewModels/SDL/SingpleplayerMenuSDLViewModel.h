#ifndef CERVISEMESTRALKA_SINGPLEPLAYERMENUSDLVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERMENUSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/SingpleplayerAbstractViewModel.h"
namespace ViewModel
{
    class SingpleplayerMenuSDLViewModel : public SingleplayerMenuAbstractViewModel
    {
    public:
        SingpleplayerMenuSDLViewModel(const Translate::TranslateEngine* Translation);
        virtual std::string NameOfPlayer();
        virtual int CountOfAI();
        virtual int Level();
    };
}
#endif
#endif //CERVISEMESTRALKA_SINGPLEPLAYERMENUSDLVIEWMODEL_H
