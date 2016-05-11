#ifndef CERVISEMESTRALKA_NIBBLESGAME_H
#define CERVISEMESTRALKA_NIBBLESGAME_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "../States/GameState.h"

namespace Game
{
    class NibbleGame
    {
    public:
        NibbleGame(ViewModel::BaseViewModel* RenderingEngine);
        void run();
        void init();

    private:
        GameState::GameState* States;
        ViewModel::BaseViewModel* RenderEngine;
    };
}


#endif //CERVISEMESTRALKA_NIBBLESGAME_H
