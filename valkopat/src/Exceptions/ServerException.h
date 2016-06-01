#ifndef CERVISEMESTRALKA_SERVEREXCEPTION_H
#define CERVISEMESTRALKA_SERVEREXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    class ServerException : public Exception
    {
    public:
        ServerException();
        ServerException(string Message);
        ServerException(string Message, int Line);
        ServerException(string Message, int Line, string FileName);
        ServerException(string Message, Exception* InnerException);
        ServerException(string ErrorMessage, int Line, string File, Exception* InnerException);
        virtual string GetType() const;
    };
}


#endif //CERVISEMESTRALKA_SERVEREXCEPTION_H
