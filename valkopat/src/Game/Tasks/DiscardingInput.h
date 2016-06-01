#ifndef CERVISEMESTRALKA_DISCARDINGINPUT_H
#define CERVISEMESTRALKA_DISCARDINGINPUT_H
#include "BaseTask.h"
#include "../../ViewModels/Abstract/AbstractInput.h"

namespace Game
{
    namespace Task
    {
        /**
         * Class that empty buffer of input
         */
        class DiscardingInput : public BaseTask
        {
        public:
            /**
             * Create new instance of DiscardingInput
             * @param Input Rendering submodule specific input
             * @return New instance of DiscardingInput
             */
            DiscardingInput(ViewModel::AbstractInput* Input);

            /**
             * Empty input buffer
             */
            virtual void run();
        private:

            /**
             * Rendering submodule specific input
             */
            ViewModel::AbstractInput* Input;
        };

    }
}


#endif //CERVISEMESTRALKA_DISCARDINGINPUT_H
