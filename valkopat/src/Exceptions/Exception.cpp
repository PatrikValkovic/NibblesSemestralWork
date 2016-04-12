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

Exceptions::Exception::Exception(string Message, int Line, Exception* InnerException)
        : Exception(Message, Line, "", InnerException)
{ }

Exceptions::Exception::Exception(string ErrorMessage, int LineNumber, string File, Exception* InnerException)
        : Message(ErrorMessage), Line(LineNumber), FileName(File), InException(InnerException)
{ }


string Exceptions::Exception::GetType() const
{
    return "Exception";
}

string Exceptions::Exception::ToString() const
{
    //TODO move to cpp file?
    string BuildingString;

    BuildingString.append("Exception of type ");
    BuildingString.append(e.GetType());
    BuildingString.append(" was throw");
    if (this->FileName != "")
        BuildingString.append(" at ").append(e.FileName);
    if (this->Line != -1)
        BuildingString.append(" on line ").append(to_string(e.Line));
    BuildingString.append(".");
    if (this->Message != "")
        BuildingString.append("Message: ").append(e.Message).append(".\n");

    if (this->InException != NULL)
    {
        BuildingString.append("\t");
        BuildingString.append(this->InException->ToString());
    }

    return BuildingString;
}


















