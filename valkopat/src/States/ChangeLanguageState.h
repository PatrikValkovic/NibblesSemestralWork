#ifndef CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#define CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class MenuGameState;

    class ChangeLanguageState : public AbstractGameState
    {
    public:
        ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();

        void AddStates(MenuGameState* MenuState);

    private:
        MenuGameState* Menu;
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
