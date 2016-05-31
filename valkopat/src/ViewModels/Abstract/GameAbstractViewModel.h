#ifndef CERVISEMESTRALKA_GAMEABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_GAMEABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"
#include "../../Game/GameContent.h"

namespace ViewModel
{
    class GameAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        GameAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~GameAbstractViewModel()
        { }

        virtual void RenderGame(Game::GameContent* ContentToRender) = 0;
    };
}

#endif //CERVISEMESTRALKA_GAMEABSTRACTVIEWMODEL_H
