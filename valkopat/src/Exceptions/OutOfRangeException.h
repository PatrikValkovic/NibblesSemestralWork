#ifndef CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
#define CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    /**
     * OutOfRangeException indicating that input is out of range
     */
    class OutOfRangeException : public Exception
    {
    public:

        /**
         * Create new instance of OutOfRangeException with empty message
         * @return new instance of OutOfRangeException class
         */
        OutOfRangeException();

        /**
         * Create new instance of OutOfRangeException with empty message
         * @return new instance of OutOfRangeException class
         */
        OutOfRangeException(string Message);

        /**
         * Create new instance of OutOfRangeException and store Message and Line
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @return new instance of OutOfRangeException class
         */
        OutOfRangeException(string Message, int Line);

        /**
         * Create new instance of OutOfRangeException and store Message, Line and Filename
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @param FileName File where problem occurs
         * @return new instance of OutOfRangeException class
         */
        OutOfRangeException(string Message, int Line, string FileName);

        /**
         * Create new instance of OutOfRangeException and store message with other exception
         * @param Message Message that informs about problem
         * @param InnerException Exception that was thrown before
         * @return new instance of OutOfRangeException class
         */
        OutOfRangeException(string Message, Exception* InnerException);

        /**
         * Create new instance of OutOfRangeException with all informations that could have
         * @param ErrorMessage Message that informs about problem
         * @param LineNumber Line where problem occurs
         * @param File File where problem occurs
         * @param InnerException Exception that was thrown before
         * @return new instance of OutOfRangeException class
         */
        OutOfRangeException(string ErrorMessage, int Line, string File, Exception* InnerException);

        /**
         * @return "OutOfRangeException"
         */
        virtual string GetType() const;
    };
}



#endif //CERVISEMESTRALKA_OUTOFRANGEEXCEPTION_H
