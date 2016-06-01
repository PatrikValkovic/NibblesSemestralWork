#ifndef CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
#define CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    class OutOfRangeException : public Exception
    {
    public:
        OutOfRangeException();
        OutOfRangeException(string Message);
        OutOfRangeException(string Message, int Line);
        OutOfRangeException(string Message, int Line, string FileName);
        OutOfRangeException(string Message, Exception* InnerException);
        OutOfRangeException(string ErrorMessage, int Line, string File, Exception* InnerException);

        virtual string GetType() const;
    };
}



#endif //CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
