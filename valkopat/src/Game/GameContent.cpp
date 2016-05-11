#include "GameContent.h"

Game::GameContent::~GameContent()
{
    std::for_each(Worms.begin(),Worms.end(),[](Worm* X){
        delete X;
    });
    delete Ground;

    Ground = NULL;
}

Game::GameContent::GameContent(vector<Worm*> Wowms, PlayGround* Playground)
        : Worms(Worms), Ground(Playground)
{ }



