#ifndef CERVISEMESTRALKA_NCURSESINPUT_H
#define CERVISEMESTRALKA_NCURSESINPUT_H
#ifdef USE_NCURSES
#include "../Abstract/AbstractInput.h"

namespace ViewModel
{
    class NCursesInput : public AbstractInput
    {
    public:
        NCursesInput();

        virtual void DiscardBuffer();

        virtual Game::Keys GetNextStroke();

        virtual void StartAgain();
    };
}


#endif
#endif //CERVISEMESTRALKA_NCURSESINPUT_H
