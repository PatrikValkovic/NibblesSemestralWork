#ifndef CERVISEMESTRALKA_NIBBLESGAME_H
#define CERVISEMESTRALKA_NIBBLESGAME_H
#include "../ViewModels/BaseViewModel.h"

class NibbleGame
{
public:
    NibbleGame(ViewModel::BaseViewModel* RenderingEngine);

private:
    ViewModel::BaseViewModel* RenderEngine;
};


#endif //CERVISEMESTRALKA_NIBBLESGAME_H
