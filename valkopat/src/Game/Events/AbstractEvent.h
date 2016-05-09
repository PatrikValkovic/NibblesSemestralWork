#ifndef CERVISEMESTRALKA_ABSTRACTEVENT_H
#define CERVISEMESTRALKA_ABSTRACTEVENT_H
#include <vector>

namespace Game
{
    namespace Event
    {
        enum Action
        {

        };

        class Abstract
        {
        public:
            ~Abstract(){}

            virtual bool HasActions() = 0;

            virtual std::vector<Action> GetActions() = 0;
        };
    }
}
#endif //CERVISEMESTRALKA_ABSTRACTEVENT_H
