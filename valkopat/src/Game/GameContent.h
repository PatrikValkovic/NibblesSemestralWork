#ifndef CERVISEMESTRALKA_GMECONTENT_H
#define CERVISEMESTRALKA_GMECONTENT_H
#include <vector>
#include <map>
#include <algorithm>
#include "Worm.h"
#include "PlayGround.h"
#include "Events/EventContainer.h"

using std::vector;
using std::map;
using Game::Worm;
using Game::PlayGround;
using Game::Event::EventContainer;

namespace Game
{
    class GameContent
    {
    private:
        Point Grub;
    public:
        GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground);
        ~GameContent();

        PlayGround* Ground;
        vector<Worm*> Worms;
        map<Worm*,Directions> MovingDirections;
        Worm* Player;
        EventContainer Events;

        Point GetGrub() const;
        void GeneratePoint();
    };
}


#endif //CERVISEMESTRALKA_GMECONTENT_H
