#include "Single.h"

Game::Event::Single::Single(Worm* Player)
        : Player(Player)
{ }

bool Game::Event::Single::HasActions()
{
    char ReadedCharacted;
    std::cin.get(ReadedCharacted);
    std::cout << "Byl nalezen znak s INT " << ReadedCharacted << " na vstupnim proudu" << std::endl;
    if (!std::cin)
    {
        std::cin.clear();
        return false;
    }
    std::cin.putback(ReadedCharacted);
    return true;
}

void Game::Event::Single::ProccessActions()
{
    using namespace std;
    char Readed;
    map<char, Directions> DirectionsTranslation = {{'w', Directions::Up},
                                                   {'s', Directions::Down},
                                                   {'a', Directions::Left},
                                                   {'d', Directions::Right}};
    while ((bool) (cin.get(Readed)))
    {
        cout << "Byl precten znak " << (int) Readed << "Ze vstupniho proudu a bude zpracovat" << std::endl;
        map<char, Directions>::iterator Finded = DirectionsTranslation.find(Readed);
        if (Finded == DirectionsTranslation.end())
            continue;
        Player->SetMoveDirection((*Finded).second);
    }
    cin.clear();
}

char Game::Event::Single::MyGetCh()
{
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return (buf);
}







