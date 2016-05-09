#ifndef CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#define CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#include "../Exceptions/OutOfRangeException.h"
#include <vector>
#include "PlayGround.h"

namespace Game
{
    class PlaygroundFactory
    {
    public:
        PlayGround* GetLevel(int Level);
        static int GetCountOfAviableLevels();
    private:
        static const int CountOfLevels = 2;
        PlayGround* FirstLevel();
        PlayGround* SecondLevel();
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
