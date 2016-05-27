#include "ServerException.h"

string Exceptions::ServerException::GetType() const
{
    return "ServerException";
}

Exceptions::ServerException::ServerException()
        : Exceptions::Exception()
{ }

Exceptions::ServerException::ServerException(string Message)
        : Exceptions::Exception(Message)
{ }

Exceptions::ServerException::ServerException(string Message, int Line)
        : Exceptions::Exception(Message, Line)
{ }

Exceptions::ServerException::ServerException(string Message, int Line, string FileName)
        : Exceptions::Exception(Message, Line, FileName)
{ }

Exceptions::ServerException::ServerException(string Message, int Line, Exception* InnerException)
        : Exceptions::Exception(Message, Line, InnerException)
{ }

Exceptions::ServerException::ServerException(string ErrorMessage, int Line, string File,
                                                           Exception* InnerException)
        : Exceptions::Exception(ErrorMessage, Line, File, InnerException)
{ }













