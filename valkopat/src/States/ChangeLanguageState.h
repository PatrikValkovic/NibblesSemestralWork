#ifndef CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#define CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#include "MenuGameState.h"
#include "AbstractGameState.h"

namespace GameState
{
    class ChangeLanguageState : public AbstractGameState
    {
    public:
        ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel, MenuGameState* MenuState);

        virtual AbstractGameState* run();

    private:
        MenuGameState* Menu;
    };
}

#endif //CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
