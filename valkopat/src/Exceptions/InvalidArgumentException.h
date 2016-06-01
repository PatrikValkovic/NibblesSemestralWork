#ifndef CERVISEMESTRALKA_INVALIDARGUMENTEXCEPTION_H
#define CERVISEMESTRALKA_INVALIDARGUMENTEXCEPTION_H
#include <string>
#include "Exception.h"

using namespace std;

namespace Exceptions
{
    /**
     * InvalidArgumentException indicating invalid parameter into method
     */
    class InvalidArgumentException : public Exception
    {
    public:

        /**
         * Create new instance of InvalidArgumentException with empty message
         * @return new instance of InvalidArgumentException class
         */
        InvalidArgumentException();

        /**
         * Create new instance of InvalidArgumentException with empty message
         * @return new instance of InvalidArgumentException class
         */
        InvalidArgumentException(string Message);

        /**
         * Create new instance of InvalidArgumentException and store Message and Line
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @return new instance of InvalidArgumentException class
         */
        InvalidArgumentException(string Message, int Line);

        /**
         * Create new instance of InvalidArgumentException and store Message, Line and Filename
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @param FileName File where problem occurs
         * @return new instance of InvalidArgumentException class
         */
        InvalidArgumentException(string Message, int Line, string FileName);

        /**
         * Create new instance of InvalidArgumentException and store message with other exception
         * @param Message Message that informs about problem
         * @param InnerException Exception that was thrown before
         * @return new instance of InvalidArgumentException class
         */
        InvalidArgumentException(string Message, Exception* InnerException);

        /**
         * Create new instance of InvalidArgumentException with all informations that could have
         * @param ErrorMessage Message that informs about problem
         * @param LineNumber Line where problem occurs
         * @param File File where problem occurs
         * @param InnerException Exception that was thrown before
         * @return new instance of InvalidArgumentException class
         */
        InvalidArgumentException(string ErrorMessage, int Line, string File, Exception* InnerException);

        /**
         * @return "InvalidArgumentException"
         */
        virtual string GetType() const;
    };
}

#endif //CERVISEMESTRALKA_INVALIDARGUMENTEXCEPTION_H
