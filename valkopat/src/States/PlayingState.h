#ifndef CERVISEMESTRALKA_PLAYINGSTATE_H
#define CERVISEMESTRALKA_PLAYINGSTATE_H
#include <map>
#include <algorithm>
#include <cstdint>
#include <vector>
#include "AbstractGameState.h"
#include "../Game/Enums.h"
#include "../Game/GameContent.h"

namespace GameStates
{
    class PlayingState : public AbstractGameState
    {
    public:
        PlayingState(ViewModel::BaseViewModel* RenderingModel);

        ~PlayingState();

        virtual AbstractGameState* run();

        void AddStates(MenuGameState* MenuState, GamePauseState* PauseState);

        void ClearContent(Game::GameContent* NewContent);

        void ValidatePositionsOfWorms();

    private:
        MenuGameState* Menu;
        GamePauseState* Pause;
        Game::GameContent* ContentOfGame = NULL;
        void MoveWorms();
        bool ProccessEvents();
        void CheckCollisions();
        void RunTasks();
    };
}

#include "GamePauseState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_PLAYINGSTATE_H
