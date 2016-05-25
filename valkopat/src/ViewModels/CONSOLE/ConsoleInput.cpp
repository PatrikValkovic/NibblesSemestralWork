#include "ConsoleInput.h"

ViewModel::ConsoleInput::ConsoleInput()
{

}

void ViewModel::ConsoleInput::DiscardBuffer()
{

}

Game::Keys ViewModel::ConsoleInput::GetNextStroke()
{
    return Game::Keys::KeyZ;
}

void ViewModel::ConsoleInput::StartAgain()
{

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







