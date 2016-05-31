#ifndef CERVISEMESTRALKA_EXCEPTION_H
#define CERVISEMESTRALKA_EXCEPTION_H
#include <exception>
#include <string>

using namespace std;


namespace Exceptions
{
    class Exception : public std::exception
    {
    private:
        string Message;
        int Line;
        Exception* InException;
        string FileName;
    public:
        virtual ~Exception();
        Exception();
        Exception(string Message);
        Exception(string Message, int Line);
        Exception(string Message, int Line, string FileName);
        Exception(string Message, int Line, Exception* InnerException);
        Exception(string ErrorMessage, int Line, string File, Exception* InnerException);

        virtual string GetType() const;

        string ToString() const;
    };
}


#endif //CERVISEMESTRALKA_EXCEPTION_H
