#include "InvalidArgumentException.h"

string Exceptions::InvalidArgumentException::GetType() const
{
    return "InvalidArgumentException";
}


Exceptions::InvalidArgumentException::InvalidArgumentException()
        : Exceptions::Exception()
{ }

Exceptions::InvalidArgumentException::InvalidArgumentException(string Message)
        : Exceptions::Exception(Message)
{ }

Exceptions::InvalidArgumentException::InvalidArgumentException(string Message, int Line)
        : Exceptions::Exception(Message, Line)
{ }

Exceptions::InvalidArgumentException::InvalidArgumentException(string Message, int Line, string FileName)
        : Exceptions::Exception(Message, Line, FileName)
{ }

Exceptions::InvalidArgumentException::InvalidArgumentException(string Message, Exception* InnerException)
        : Exceptions::Exception(Message, InnerException)
{ }

Exceptions::InvalidArgumentException::InvalidArgumentException(string ErrorMessage, int Line, string File,
                                                               Exception* InnerException)
        : Exceptions::Exception(ErrorMessage, Line, File, InnerException)
{ }

