#ifndef CERVISEMESTRALKA_INVALIDFORMATEXCEPTION_H
#define CERVISEMESTRALKA_INVALIDFORMATEXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    /**
     * InvalidFormatException indicating invalid format of input
     */
    class InvalidFormatException : public Exception
    {
    public:

        /**
         * Create new instance of InvalidFormatException with empty message
         * @return new instance of InvalidFormatException class
         */
        InvalidFormatException();

        /**
         * Create new instance of InvalidFormatException with empty message
         * @return new instance of InvalidFormatException class
         */
        InvalidFormatException(string Message);

        /**
         * Create new instance of InvalidFormatException and store Message and Line
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @return new instance of InvalidFormatException class
         */
        InvalidFormatException(string Message, int Line);

        /**
         * Create new instance of InvalidFormatException and store Message, Line and Filename
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @param FileName File where problem occurs
         * @return new instance of InvalidFormatException class
         */
        InvalidFormatException(string Message, int Line, string FileName);

        /**
         * Create new instance of InvalidFormatException and store message with other exception
         * @param Message Message that informs about problem
         * @param InnerException Exception that was thrown before
         * @return new instance of InvalidFormatException class
         */
        InvalidFormatException(string Message, Exception* InnerException);

        /**
         * Create new instance of InvalidFormatException with all informations that could have
         * @param ErrorMessage Message that informs about problem
         * @param LineNumber Line where problem occurs
         * @param File File where problem occurs
         * @param InnerException Exception that was thrown before
         * @return new instance of InvalidFormatException class
         */
        InvalidFormatException(string ErrorMessage, int Line, string File, Exception* InnerException);

        /**
         * @return "InvalidFormatException"
         */
        virtual string GetType() const;
    };
}


#endif //CERVISEMESTRALKA_INVALIDFORMATEXCEPTION_H
