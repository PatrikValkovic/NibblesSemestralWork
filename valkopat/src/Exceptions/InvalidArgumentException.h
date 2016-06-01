#ifndef CERVISEMESTRALKA_INVALIDARGUMENTEXCEPTION_H
#define CERVISEMESTRALKA_INVALIDARGUMENTEXCEPTION_H
#include <string>
#include "Exception.h"

using namespace std;

namespace Exceptions
{
    class InvalidArgumentException : public Exception
    {
    public:
        InvalidArgumentException();
        InvalidArgumentException(string Message);
        InvalidArgumentException(string Message, int Line);
        InvalidArgumentException(string Message, int Line, string FileName);
        InvalidArgumentException(string Message, Exception* InnerException);
        InvalidArgumentException(string ErrorMessage, int Line, string File, Exception* InnerException);

        virtual string GetType() const;
    };
}

#endif //CERVISEMESTRALKA_INVALIDARGUMENTEXCEPTION_H
