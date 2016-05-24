#ifndef CERVISEMESTRALKA_BFSAI_H
#define CERVISEMESTRALKA_BFSAI_H
#include <climits>
#include <set>
#include <queue>
#include "BaseTask.h"
#include "../GameContent.h"
#include "../Worm.h"

namespace Game
{
    namespace Task
    {
        class BFSAI : public BaseTask
        {
        public:
            BFSAI(Worm* AIWorm,GameContent* Content);
            virtual void run();
        private:
            Worm* ControlledWorm;
            GameContent* ContentOfGame;

            Directions BFS(uint32_t** map, Point BeginOfSearch, Point EndPoint) const;
            set<Point> GeneratePointsAround(Point AroundToGenerate) const;
        };
    }
}


#endif //CERVISEMESTRALKA_BFSAI_H
