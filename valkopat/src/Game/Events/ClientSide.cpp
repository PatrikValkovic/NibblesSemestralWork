#include "ClientSide.h"

Game::Event::ClientSide::ClientSide()
{

}

bool Game::Event::ClientSide::HasActions()
{
    return false;
}

std::vector<Game::Event::Action> Game::Event::ClientSide::GetActions()
{
    return std::vector<Action>();
}





