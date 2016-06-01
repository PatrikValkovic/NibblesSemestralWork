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
    /**
     * Container for all objects in game
     */
    class GameContent
    {
    private:
        /**
         * Where is actual position of food
         */
        Point Food;
    public:
        /**
         * Create new empty instance of GameContent
         * @return New instance of GameContent
         */
        GameContent();

        /**
         * Create new instance of GameContent with Worms and Playground
         * @param Worms Worms controlled by PC
         * @param Player Player Game::Worm
         * @param Playground Playground to use
         * @return New instance of GameContent
         */
        GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground);

        /**
         * Desctructor delete all objects in game include events, tasks, worms and playground
         */
        ~GameContent();

        /**
         * Current playing playground
         */
        PlayGround* Ground;

        /**
         * All worms in game, include player worms
         */
        vector<Worm*> Worms;

        /**
         * Event container containing all events in game
         */
        EventContainer Events;

        /**
         * Vector of Game::Task::BaseTask containing all tasks in game
         */
        vector<Game::Task::BaseTask*> Tasks;

        /**
         * Get current position of food
         * @return Game::Point Position of food
         */
        Point GetFood() const;
        /**
         * Generate new position of Food
         */
        void GenerateFood();

        /**
         * Create array of size char[HeightOfGame][WidthOfGame] allocated by new char[]
         * @return Array for playfield
         */
        char** CreateArrayForGame();
        /**
         * Method to delete array previously created by Game::GameContent::CreateArrayForGame
         * @param Array Array to delete
         */
        void DeleteArrayForGame(char**& Array);
    };
}


#endif //CERVISEMESTRALKA_GMECONTENT_H
