#include "Exception.h"

Exceptions::Exception::~Exception()
{
    delete InException;
}

Exceptions::Exception::Exception() : Exception("")
{ }

Exceptions::Exception::Exception(string Message) : Exception(Message, -1)
{ }

Exceptions::Exception::Exception(string Message, int Line) : Exception(Message, Line, NULL)
{ }

Exceptions::Exception::Exception(string Message, int Line, string FileName)
        : Exception(Message, Line, FileName, NULL)
{ }

Exceptions::Exception::Exception(string Message, Exception* InnerException)
        : Exception(Message, -1, "", InnerException)
{ }

Exceptions::Exception::Exception(string ErrorMessage, int LineNumber, string File, Exception* InnerException)
        : Message(ErrorMessage), Line(LineNumber), InException(InnerException), FileName(File)
{ }


string Exceptions::Exception::GetType() const
{
    return "Exception";
}

string Exceptions::Exception::ToString() const
{
    string BuildingString;

    BuildingString.append("Exception of type ");
    BuildingString.append(this->GetType());
    BuildingString.append(" was throw");
    if (this->FileName != "")
        BuildingString.append(" at ").append(this->FileName);
    if (this->Line != -1)
        BuildingString.append(" on line ").append(to_string(this->Line));
    BuildingString.append(".");
    if (this->Message != "")
        BuildingString.append("Message: ").append(this->Message).append(".\n");

    if (this->InException != NULL)
    {
        BuildingString.append("\t");
        BuildingString.append(this->InException->ToString());
    }

    return BuildingString;
}


















