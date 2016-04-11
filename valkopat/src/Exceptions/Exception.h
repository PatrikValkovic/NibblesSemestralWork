#ifndef CERVISEMESTRALKA_EXCEPTION_H
#define CERVISEMESTRALKA_EXCEPTION_H
#include <exception>
#include <string>

using namespace std;


namespace Exceptions
{
    class Exception : public std::exception
    {
        virtual ~Exception();
        Exception();
        Exception(string Message);
        Exception(string Message, int Line);
        Exception(string Message, int Line, string FileName);
        Exception(string Message, int Line, Exception* InnerException);
        Exception(string Message, int Line, string FunctionName, Exception* InnerException);

        friend ostream& operator<<(ostream& os, const Exception& e);

    protected:
        virtual string GetType() const;
    private:
        string Message;
        int Line;
        Exception* InnerException;
        string FileName;
    };
}

#endif //CERVISEMESTRALKA_EXCEPTION_H
