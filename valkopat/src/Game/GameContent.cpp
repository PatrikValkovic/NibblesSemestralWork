#include "GameContent.h"

Game::GameContent::~GameContent()
{
    std::for_each(Worms.begin(),Worms.end(),[](Worm* X){
        delete X;
    });
    delete Ground;
    delete Player;
    Events.DeleteAllEvents();

    Ground = NULL;
    Player = NULL;
}

Game::GameContent::GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground)
        : Ground(Playground), Player(Player)
{
    this->Worms = Worms;
}



