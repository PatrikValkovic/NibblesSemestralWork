#ifndef CERVISEMESTRALKA_CONSOLEINPUT_H
#define CERVISEMESTRALKA_CONSOLEINPUT_H
#include "../Abstract/AbstractInput.h"

namespace ViewModel
{
    class ConsoleInput : public AbstractInput
    {
    public:
        ConsoleInput();

        virtual void DiscardBuffer();

        virtual Game::Keys GetNextStroke();

        virtual void StartAgain();
    };
}


#endif //CERVISEMESTRALKA_CONSOLEINPUT_H
