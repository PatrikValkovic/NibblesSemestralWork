#ifndef CERVISEMESTRALKA_SDLINPUT_H
#define CERVISEMESTRALKA_SDLINPUT_H
#include "../Abstract/AbstractInput.h"

namespace ViewModel
{
    class SDLInput
    {
    public:
        SDLInput();

        virtual void DiscardBuffer();

        virtual Game::Keys GetNextStroke();

        virtual void StartAgain();
    };
}


#endif //CERVISEMESTRALKA_SDLINPUT_H
