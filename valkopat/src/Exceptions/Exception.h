#ifndef CERVISEMESTRALKA_EXCEPTION_H
#define CERVISEMESTRALKA_EXCEPTION_H
#include <exception>
#include <string>

using namespace std;


namespace Exceptions
{
    /**
     * Base class for all exceptions in project. Contain informations about Message, Line, Filename and InnerException
     */
    class Exception : public std::exception
    {
    private:
        string Message;
        int Line;
        Exception* InException;
        string FileName;
    public:

        /**
         *  Delete exception and all inner exceptions
         */
        virtual ~Exception();

        /**
         * Create new instance of Exception with empty message
         * @return new instance of Exception class
         */
        Exception();

        /**
         * Create new instance of Exception with message
         * @param Message Message that informs about problem
         * @return new instance of Exception class
         */
        Exception(string Message);

        /**
         * Create new instance of Exception and store Message and Line
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @return new instance of Exception class
         */
        Exception(string Message, int Line);

        /**
         * Create new instance of Exception and store Message, Line and Filename
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @param FileName File where problem occurs
         * @return new instance of Exception class
         */
        Exception(string Message, int Line, string FileName);

        /**
         * Create new instance of Exception and store message with other exception
         * @param Message Message that informs about problem
         * @param InnerException Exception that was thrown before
         * @return new instance of Exception class
         */
        Exception(string Message, Exception* InnerException);

        /**
         *
         * @param ErrorMessage Message that informs about problem
         * @param LineNumber Line where problem occurs
         * @param File File where problem occurs
         * @param InnerException Exception that was thrown before
         * @return new instance of Exception class
         */
        Exception(string ErrorMessage, int Line, string File, Exception* InnerException);

        /**
         * Return type of exception in string
         * @return string that represent type of exception
         */
        virtual string GetType() const;

        /**
         * Create string that have all informations about problem
         * @return string with informations about problem
         */
        string ToString() const;
    };
}


#endif //CERVISEMESTRALKA_EXCEPTION_H
