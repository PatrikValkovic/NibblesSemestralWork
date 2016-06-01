#ifndef CERVISEMESTRALKA_ABSTRACTEVENT_H
#define CERVISEMESTRALKA_ABSTRACTEVENT_H
#include <vector>

namespace Game
{
    namespace Event
    {
        /**
         * Base abstract class for Events
         */
        class Abstract
        {
        public:

            /**
             * Destructor
             */
            virtual ~Abstract(){}

            /**
             * Check if are events to proccess
             * @return True if are events to proccess, false otherwise
             */
            virtual bool HasActions() = 0;

            /**
             * Proccess all waiting events
             * @return False if game should end, true if continue
             */
            virtual bool ProccessActions() = 0;
        };
    }
}
#endif //CERVISEMESTRALKA_ABSTRACTEVENT_H
