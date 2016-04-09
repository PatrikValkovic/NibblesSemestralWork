#ifndef CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#define CERVISEMESTRALKA_ABSTRACTGAMESTATE_H

namespace GameState
{
    class AbstractGameState
    {
    public:
        virtual ~AbstractGameState()
        { }

        virtual AbstractGameState* run() = 0;
    };
}
#endif //CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
