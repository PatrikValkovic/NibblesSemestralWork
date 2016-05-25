#ifdef USE_CONSOLE
#include "ConsoleInput.h"

const std::map<char,Game::Keys> ViewModel::ConsoleInput::KeyTranslate
        {
                std::pair<char,Game::Keys>('a',Game::Keys::KeyA),
                std::pair<char,Game::Keys>('b',Game::Keys::KeyB),
                std::pair<char,Game::Keys>('c',Game::Keys::KeyC),
                std::pair<char,Game::Keys>('d',Game::Keys::KeyD),
                std::pair<char,Game::Keys>('e',Game::Keys::KeyE),
                std::pair<char,Game::Keys>('f',Game::Keys::KeyF),
                std::pair<char,Game::Keys>('g',Game::Keys::KeyG),
                std::pair<char,Game::Keys>('h',Game::Keys::KeyH),
                std::pair<char,Game::Keys>('i',Game::Keys::KeyI),
                std::pair<char,Game::Keys>('j',Game::Keys::KeyJ),
                std::pair<char,Game::Keys>('k',Game::Keys::KeyK),
                std::pair<char,Game::Keys>('l',Game::Keys::KeyL),
                std::pair<char,Game::Keys>('m',Game::Keys::KeyM),
                std::pair<char,Game::Keys>('n',Game::Keys::KeyN),
                std::pair<char,Game::Keys>('o',Game::Keys::KeyO),
                std::pair<char,Game::Keys>('p',Game::Keys::KeyP),
                std::pair<char,Game::Keys>('q',Game::Keys::KeyQ),
                std::pair<char,Game::Keys>('r',Game::Keys::KeyR),
                std::pair<char,Game::Keys>('s',Game::Keys::KeyS),
                std::pair<char,Game::Keys>('t',Game::Keys::KeyT),
                std::pair<char,Game::Keys>('u',Game::Keys::KeyU),
                std::pair<char,Game::Keys>('v',Game::Keys::KeyV),
                std::pair<char,Game::Keys>('w',Game::Keys::KeyW),
                std::pair<char,Game::Keys>('x',Game::Keys::KeyX),
                std::pair<char,Game::Keys>('y',Game::Keys::KeyY),
                std::pair<char,Game::Keys>('z',Game::Keys::KeyZ),
                std::pair<char,Game::Keys>('0',Game::Keys::Key0),
                std::pair<char,Game::Keys>('1',Game::Keys::Key1),
                std::pair<char,Game::Keys>('2',Game::Keys::Key2),
                std::pair<char,Game::Keys>('3',Game::Keys::Key3),
                std::pair<char,Game::Keys>('4',Game::Keys::Key4),
                std::pair<char,Game::Keys>('5',Game::Keys::Key5),
                std::pair<char,Game::Keys>('6',Game::Keys::Key6),
                std::pair<char,Game::Keys>('7',Game::Keys::Key7),
                std::pair<char,Game::Keys>('8',Game::Keys::Key8),
                std::pair<char,Game::Keys>('9',Game::Keys::Key9),
        };


ViewModel::ConsoleInput::ConsoleInput() : Index(0)
{

}

void ViewModel::ConsoleInput::DiscardBuffer()
{
    this->Buffer.clear();
}

Game::Keys ViewModel::ConsoleInput::GetNextStroke()
{
    using Game::Keys;

    if(Index==(int)this->Buffer.size())
    {
        //TODO
    }

    if(Index==(int)this->Buffer.size())
        return Keys::NONE;
    return this->Buffer[Index++];
}

void ViewModel::ConsoleInput::StartAgain()
{
    Index = 0;
}

void ViewModel::ConsoleInput::BackMode(termios old)
{
    //ZDROJ: http://stackoverflow.com/a/912796/3797407
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        throw new Exceptions::Exception("tcsetattr ~ICANON");
}

termios ViewModel::ConsoleInput::SetMode()
{
    //ZDROJ: http://stackoverflow.com/a/912796/3797407
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        throw new Exceptions::Exception("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        throw new Exceptions::Exception("tcsetattr ICANON");
    return old;
}

int ViewModel::ConsoleInput::kbhit()
{
    //ZDROJ: http://stackoverflow.com/a/912796/3797407
    int i;
    ioctl(0, FIONREAD, &i);
    return i; /* return a count of chars available to read */
}

#endif







