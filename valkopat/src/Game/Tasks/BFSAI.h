#ifndef CERVISEMESTRALKA_BFSAI_H
#define CERVISEMESTRALKA_BFSAI_H
#include <climits>
#include <set>
#include <queue>
#include <vector>
#include "BaseAITask.h"
#include "../../Exceptions/InvalidArgumentException.h"

namespace Game
{
    namespace Task
    {
        /**
         * AITask that inernally use BFS
         */
        class BFSAI : public BaseAITask
        {
        public:
            /**
             * Create new instance of BFSAI
             * @param AIWorm Game::Worm to control
             * @param Content Game::GameContent of game
             * @return New instance of BFSAI
             */
            BFSAI(Worm* AIWorm,GameContent* Content);

            /**
             * Run BFS and find the shorted path
             */
            virtual void run();

            virtual BaseAITask* CreateInstance(Worm* WormToControl,GameContent* Game);
        private:
            /**
             * Run BFS
             * @param map Representation of gamefield
             * @param BeginOfSearch Where begin search
             * @param EndPoint Where end search
             * @return Direction to move
             */
            Actions BFS(uint32_t** map, Point BeginOfSearch, Point EndPoint);
            /**
             * Generate points around specific Game::Point, works also in the edge of gamefield
             * @param AroundToGenerate Game::Point around which generate points
             * @return Vector of poitns around
             */
            vector<Point> GeneratePointsAround(Point AroundToGenerate);
            /**
             * Choose direction, which should worm move
             * @param From From which point
             * @param To To which point
             * @return Direction to move
             */
            Actions ResolveDirection(Point From, Point To);
        };
    }
}


#endif //CERVISEMESTRALKA_BFSAI_H
