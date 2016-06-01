#ifndef CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#define CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#include <algorithm>
#include "../ViewModels/Abstract/SettingsAbstractViewModel.h"
#include "AbstractGameState.h"

namespace GameStates
{
    /**
     * State where player could change his setting
     */
    class SettingsState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of SettingState
         * @param RenderingModel Rendering submodule
         * @return New instance of SettingState
         */
        SettingsState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Change language or keybinding
         * @return State with game menu
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param MenuState State with game menu
         */
        void AddStates(MenuGameState* MenuState);

    private:
        MenuGameState* Menu;
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
