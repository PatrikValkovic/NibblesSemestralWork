#ifndef CERVISEMESTRALKA_NIBBLESGAME_H
#define CERVISEMESTRALKA_NIBBLESGAME_H
#include "../ViewModels/BaseViewModel.h"

namespace Game
{
    class NibbleGame
    {
    public:
        NibbleGame(ViewModel::BaseViewModel* RenderingEngine);
        void run();
        void init();

    private:
        ViewModel::BaseViewModel* RenderEngine;
    };
}


#endif //CERVISEMESTRALKA_NIBBLESGAME_H
