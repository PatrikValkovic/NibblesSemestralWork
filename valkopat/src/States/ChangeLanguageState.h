#ifndef CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#define CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class MenuGameState;

    class ChangeLanguageState : public AbstractGameState
    {
    public:
        ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel, MenuGameState* MenuState);

        virtual AbstractGameState* run();

    private:
        MenuGameState* Menu;
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
