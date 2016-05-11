#include "Single.h"

Game::Event::Single::Single(Worm* Player)
        : Player(Player)
{ }

bool Game::Event::Single::HasActions()
{
    termios Mode = this->SetMode();
    int Count = this->kbhit();
    this->BackMode(Mode);
    return Count>0;
}

void Game::Event::Single::ProccessActions()
{
    using namespace std;
    char Readed;
    map<char, Directions> DirectionsTranslation = {{'w', Directions::Up},
                                                   {'s', Directions::Down},
                                                   {'a', Directions::Left},
                                                   {'d', Directions::Right}};
    termios Mode = this->SetMode();
    int Count = this->kbhit();
    for(int a=0;a<Count;a++)
    {
        Readed = (char)getchar();
        Directions NextDirection;
        try {
            NextDirection = DirectionsTranslation.at(Readed);
        } catch(out_of_range e) {
            NextDirection = Player->GetMoveDirection();
        }
        this->Player->SetMoveDirection(NextDirection);
    }
    this->BackMode(Mode);
}

void Game::Event::Single::BackMode(termios old)
{
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
}

termios Game::Event::Single::SetMode()
{
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    return old;
}

int Game::Event::Single::kbhit()
{
    int i;
    ioctl(0, FIONREAD, &i);
    return i; /* return a count of chars available to read */
}







