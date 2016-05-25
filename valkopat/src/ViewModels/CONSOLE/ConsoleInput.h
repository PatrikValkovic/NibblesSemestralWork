#ifndef CERVISEMESTRALKA_CONSOLEINPUT_H
#define CERVISEMESTRALKA_CONSOLEINPUT_H
#ifdef USE_CONSOLE
#include <map>
#include <vector>
#include <termios.h>
#include <sys/ioctl.h>
#include "../Abstract/AbstractInput.h"
#include "../../Exceptions/Exception.h"

namespace ViewModel
{
    class ConsoleInput : public AbstractInput
    {
    public:
        ConsoleInput();

        virtual void DiscardBuffer();

        virtual Game::Keys GetNextStroke();

        virtual void StartAgain();

    private:
        std::vector<Game::Keys> Buffer;

        static const std::map<char,Game::Keys> KeyTranslate;

        void BackMode(termios old);
        termios SetMode();
        int kbhit();
        int Index;
    };
}

#endif
#endif //CERVISEMESTRALKA_CONSOLEINPUT_H
