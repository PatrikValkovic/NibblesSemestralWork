#ifndef CERVISEMESTRALKA_GMECONTENT_H
#define CERVISEMESTRALKA_GMECONTENT_H
#include <vector>
#include <algorithm>
#include "../Game/Worm.h"
#include "../Game/PlayGround.h"
using std::vector;
using Game::Worm;
using Game::PlayGround;

namespace Game
{
    class GameContent
    {
    public:
        GameContent(vector<Worm*> Wowms,Worm* Player, PlayGround* Playground);
        ~GameContent();

        PlayGround* Ground;
        vector<Worm*> Worms;
        Worm* Player;
    };
}


#endif //CERVISEMESTRALKA_GMECONTENT_H
