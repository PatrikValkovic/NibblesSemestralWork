#include "InvalidFormatException.h"

string Exceptions::InvalidFormatException::GetType() const
{
    return "InvalidFormatException";
}

Exceptions::InvalidFormatException::InvalidFormatException()
        : Exceptions::Exception()
{ }

Exceptions::InvalidFormatException::InvalidFormatException(string Message)
        : Exceptions::Exception(Message)
{ }

Exceptions::InvalidFormatException::InvalidFormatException(string Message, int Line)
        : Exceptions::Exception(Message, Line)
{ }

Exceptions::InvalidFormatException::InvalidFormatException(string Message, int Line, string FileName)
        : Exceptions::Exception(Message, Line, FileName)
{ }

Exceptions::InvalidFormatException::InvalidFormatException(string Message, int Line, Exception* InnerException)
        : Exceptions::Exception(Message, Line, InnerException)
{ }

Exceptions::InvalidFormatException::InvalidFormatException(string ErrorMessage, int Line, string File,
                                                               Exception* InnerException)
        : Exceptions::Exception(ErrorMessage, Line, File, InnerException)
{ }


