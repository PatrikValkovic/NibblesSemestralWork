#ifndef CERVISEMESTRALKA_GMECONTENT_H
#define CERVISEMESTRALKA_GMECONTENT_H
#include <vector>
#include <map>
#include <algorithm>
#include "Worm.h"
#include "PlayGround.h"
#include "Events/EventContainer.h"
#include "Tasks/BaseTask.h"

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
        Point Food;
    public:
        GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground);
        ~GameContent();

        PlayGround* Ground;
        vector<Worm*> Worms;
        map<Worm*,Directions> MovingDirections;
        Worm* Player;
        EventContainer Events;
        vector<Game::Task::BaseTask*> Tasks;

        Point GetFood() const;
        void GenerateFood();
    };
}


#endif //CERVISEMESTRALKA_GMECONTENT_H
