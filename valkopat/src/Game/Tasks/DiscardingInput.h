#ifndef CERVISEMESTRALKA_DISCARDINGINPUT_H
#define CERVISEMESTRALKA_DISCARDINGINPUT_H
#include "BaseTask.h"
#include "../../ViewModels/Abstract/AbstractInput.h"

namespace Game
{
    namespace Task
    {
        class DiscardingInput : public BaseTask
        {
        public:
            DiscardingInput(ViewModel::AbstractInput* Input);
            virtual void run();
        private:
            ViewModel::AbstractInput* Input;
        };

    }
}


#endif //CERVISEMESTRALKA_DISCARDINGINPUT_H
