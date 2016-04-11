#include "Exception.h"

Exceptions::Exception::~Exception()
{
    delete InnerException;
}

Exceptions::Exception::Exception() : Exception("")
{ }

Exceptions::Exception::Exception(string Message) : Exception(Message, -1)
{ }

Exceptions::Exception::Exception(string Message, int Line) : Exceptions(Message, Line, NULL)
{ }

Exceptions::Exception::Exception(string Message, int Line, string FileName)
        : Exception(Message, Line, FileName, NULL)
{ }

Exceptions::Exception::Exception(string Message, int Line, Exception* InnerException)
        : Exception(Message, Line, "", InnerException)
{ }

Exceptions::Exception::Exception(string Message, int Line, string FileName, Exception* InnerException)
        : Message(Message), Line(Line), FileName(FileName), InnerException(InnerException)
{ }

ostream& operator<<(ostream& os, const Exceptions::Exception& e)
{
    string BuildingString;

    BuildingString.append("Exception of type ");
    BuildingString.append(e.GetType());
    BuildingString.append(" was throw");
    if(e.FileName!="")
        BuildingString.append(" at ").append(e.FileName);
    if(e.Line!=-1)
        BuildingString.append(" on line ").append(to_string(e.Line));
    BuildingString.append(".");
    if(Message!="")
        BuildingString.append("Message: ").append(e.Message).append(".\n");

    if(InnerException!=NULL)
    {
        BuildingString.append("\tInnerException: ");
        os << BuildingString;
        os << *InnerException;
    }
    return os;
}

string Exceptions::Exception::GetType() const
{
    return "Exception";
}

















