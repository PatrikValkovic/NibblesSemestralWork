#ifndef CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#define CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#include <vector>
#include <map>
#include <string>
#include "../Exceptions/OutOfRangeException.h"
#include "PlayGround.h"

using namespace std;

namespace Game
{
    class PlaygroundFactory
    {
    public:
        static PlayGround* GetLevel(int Level);
        static map<int,string> GetCountOfAviableLevels();
    private:
        static PlayGround* FirstLevel();
        static PlayGround* SecondLevel();
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
