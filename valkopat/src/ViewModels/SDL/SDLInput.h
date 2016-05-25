#ifndef CERVISEMESTRALKA_SDLINPUT_H
#define CERVISEMESTRALKA_SDLINPUT_H
#ifdef USE_SDL
#include "../Abstract/AbstractInput.h"

namespace ViewModel
{
    class SDLInput : public AbstractInput
    {
    public:
        SDLInput();

        virtual void DiscardBuffer();

        virtual Game::Keys GetNextStroke();

        virtual void StartAgain();
    };
}

#endif
#endif //CERVISEMESTRALKA_SDLINPUT_H
