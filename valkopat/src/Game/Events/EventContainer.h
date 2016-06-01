#ifndef CERVISEMESTRALKA_EVENTCONTAINER_H
#define CERVISEMESTRALKA_EVENTCONTAINER_H
#include <vector>
#include <algorithm>
#include "AbstractEvent.h"

namespace Game
{
    namespace Event
    {
        /**
         * Container for events
         */
        class EventContainer
        {
            /**
             * Vector of all events
             */
            std::vector<Abstract*> Events;
        public:
            /**
             * Run all events
             * @return
             */
            bool ProccessEvents();

            /**
             * Add event to Container
             * @param E Event to add
             */
            void AddEvent(Abstract* E);

            /**
             * Remove event from container
             * @param E Event to remove
             * @return True if was event removed, false otherwise
             */
            bool RemoveEvent(Abstract* E);

            /**
             * Remove and delete all events in container
             */
            void DeleteAllEvents();
        };
    }
}


#endif //CERVISEMESTRALKA_EVENTCONTAINER_H
