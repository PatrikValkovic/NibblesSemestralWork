#include "OutOfRangeException.h"

string Exceptions::OutOfRangeException::GetType() const
{
    return "OutOfRangeException";
}

Exceptions::OutOfRangeException::OutOfRangeException()
        : Exceptions::Exception()
{ }

Exceptions::OutOfRangeException::OutOfRangeException(string Message)
        : Exceptions::Exception(Message)
{ }

Exceptions::OutOfRangeException::OutOfRangeException(string Message, int Line)
        : Exceptions::Exception(Message, Line)
{ }

Exceptions::OutOfRangeException::OutOfRangeException(string Message, int Line, string FileName)
        : Exceptions::Exception(Message, Line, FileName)
{ }

Exceptions::OutOfRangeException::OutOfRangeException(string Message, Exception* InnerException)
        : Exceptions::Exception(Message, InnerException)
{ }

Exceptions::OutOfRangeException::OutOfRangeException(string ErrorMessage, int Line, string File,
                                                           Exception* InnerException)
        : Exceptions::Exception(ErrorMessage, Line, File, InnerException)
{ }

