#ifndef CERVISEMESTRALKA_GMECONTENT_H
#define CERVISEMESTRALKA_GMECONTENT_H
#include <vector>
#include <map>
#include <algorithm>
#include "../Game/Worm.h"
#include "../Game/PlayGround.h"
using std::vector;
using std::map;
using Game::Worm;
using Game::PlayGround;

namespace Game
{
    class GameContent
    {
    public:
        GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground);
        ~GameContent();

        PlayGround* Ground;
        vector<Worm*> Worms;
        map<Worm*,Directions> MovingDirections;
        Worm* Player;
    };
}


#endif //CERVISEMESTRALKA_GMECONTENT_H
