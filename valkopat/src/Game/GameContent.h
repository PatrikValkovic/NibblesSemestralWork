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
        GameContent();
        GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground);
        ~GameContent();

        PlayGround* Ground;
        vector<Worm*> Worms;
        map<Worm*,Actions> MovingDirections;
        vector<Worm*> Players;
        EventContainer Events;
        vector<Game::Task::BaseTask*> Tasks;

        Point GetFood() const;
        void GenerateFood();

        char** CreateArrayForGame();
        void DeleteArrayForGame(char**& Array);
    };
}


#endif //CERVISEMESTRALKA_GMECONTENT_H
