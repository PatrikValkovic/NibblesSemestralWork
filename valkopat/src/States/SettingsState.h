#ifndef CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#define CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#include <algorithm>
#include "../ViewModels/Abstract/SettingsAbstractViewModel.h"
#include "AbstractGameState.h"

namespace GameStates
{
    class SettingsState : public AbstractGameState
    {
    public:
        SettingsState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();

        void AddStates(MenuGameState* MenuState);

    private:
        MenuGameState* Menu;
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
