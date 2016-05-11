#include "Single.h"

Game::Event::Single::Single()
{ }

bool Game::Event::Single::HasActions()
{
    int Returned = std::cin.peek();
    if(Returned==EOF)
    {
        std::cin.clear();
        return false;
    }
    return true;
}

void Game::Event::Single::ProccessActions()
{
   //TODO
}





