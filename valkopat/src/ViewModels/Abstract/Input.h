#ifndef CERVISEMESTRALKA_INPUT_H
#define CERVISEMESTRALKA_INPUT_H
#include "../../Game/Enums.h"

namespace ViewModel
{
    class Input
    {
    public:
        virtual ~Input()
        {}

        virtual void DiscardBuffer() = 0;

        virtual Game::Keys GetNextStroke() = 0;

        virtual void StartAgain() = 0;
    };
}
#endif //CERVISEMESTRALKA_INPUT_H
