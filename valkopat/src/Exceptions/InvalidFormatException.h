#ifndef CERVISEMESTRALKA_INVALIDFORMATEXCEPTION_H
#define CERVISEMESTRALKA_INVALIDFORMATEXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    class InvalidFormatException : public Exception
    {
    public:
        InvalidFormatException();
        InvalidFormatException(string Message);
        InvalidFormatException(string Message, int Line);
        InvalidFormatException(string Message, int Line, string FileName);
        InvalidFormatException(string Message, int Line, Exception* InnerException);
        InvalidFormatException(string ErrorMessage, int Line, string File, Exception* InnerException);

        virtual string GetType() const;
    };
}


#endif //CERVISEMESTRALKA_INVALIDFORMATEXCEPTION_H
