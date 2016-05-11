#ifndef CERVISEMESTRALKA_EVENTCONTAINER_H
#define CERVISEMESTRALKA_EVENTCONTAINER_H
#include <vector>
#include <algorithm>
#include "AbstractEvent.h"

namespace Game
{
    namespace Event
    {
        class EventContainer
        {
            std::vector<Abstract*> Events;
        public:
            bool ProccessEvents();
            void AddEvent(Abstract* E);
            bool RemoveEvent(Abstract* E);
            void DeleteAllEvents();
        };
    }
}


#endif //CERVISEMESTRALKA_EVENTCONTAINER_H
