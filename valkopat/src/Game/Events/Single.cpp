#include "Single.h"

Game::Event::Single::Single()
{ }

bool Game::Event::Single::HasActions()
{
    return false;
}

std::vector<Game::Event::Action> Game::Event::Single::GetActions()
{
    return std::vector<Action>();
}





