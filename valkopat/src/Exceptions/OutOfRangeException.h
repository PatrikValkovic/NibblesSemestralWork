#ifndef CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
#define CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    class OutOfRangeException : public Exception
    {
    public:
        virtual string GetType() const;
    };
}



#endif //CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
