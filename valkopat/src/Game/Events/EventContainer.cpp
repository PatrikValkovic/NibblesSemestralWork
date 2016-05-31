#include "EventContainer.h"

bool Game::Event::EventContainer::ProccessEvents()
{
    using Game::Event::Abstract;
    using std::vector;
    vector<Abstract*>::iterator Moving = this->Events.begin();
    vector<Abstract*>::iterator End = this->Events.end();
    bool Continue = true;
    for(;Moving!=End;Moving++)
        if((*Moving)->HasActions())
            if(!((*Moving)->ProccessActions()))
                Continue = false;
    return Continue;
}

void Game::Event::EventContainer::AddEvent(Abstract* E)
{
    this->Events.push_back(E);
}

void Game::Event::EventContainer::DeleteAllEvents()
{
    using Game::Event::Abstract;
    using std::vector;
    vector<Abstract*>::iterator Moving = this->Events.begin();
    vector<Abstract*>::iterator End = this->Events.end();
    for(;Moving!=End;Moving++)
        delete *Moving;
    this->Events.clear();
}

bool Game::Event::EventContainer::RemoveEvent(Abstract* E)
{
    using Game::Event::Abstract;
    using std::vector;
    vector<Abstract*>::iterator Instance = std::find(this->Events.begin(), this->Events.end(), E);
    if(Instance==this->Events.end())
        return false;
    this->Events.erase(Instance);
    return true;
}







