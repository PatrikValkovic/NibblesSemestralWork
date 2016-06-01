#ifndef CERVISEMESTRALKA_SERVEREXCEPTION_H
#define CERVISEMESTRALKA_SERVEREXCEPTION_H
#include "Exception.h"

namespace Exceptions
{
    /**
     * ServerException indicating problem with server
     */
    class ServerException : public Exception
    {
    public:

        /**
         * Create new instance of ServerException with empty message
         * @return new instance of ServerException class
         */
        ServerException();

        /**
         * Create new instance of ServerException with empty message
         * @return new instance of ServerException class
         */
        ServerException(string Message);

        /**
         * Create new instance of ServerException and store Message and Line
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @return new instance of ServerException class
         */
        ServerException(string Message, int Line);

        /**
         * Create new instance of ServerException and store Message, Line and Filename
         * @param Message Message that informs about problem
         * @param Line Line where problem occurs
         * @param FileName File where problem occurs
         * @return new instance of ServerException class
         */
        ServerException(string Message, int Line, string FileName);

        /**
         * Create new instance of ServerException and store message with other exception
         * @param Message Message that informs about problem
         * @param InnerException Exception that was thrown before
         * @return new instance of ServerException class
         */
        ServerException(string Message, Exception* InnerException);

        /**
         * Create new instance of ServerException with all informations that could have
         * @param ErrorMessage Message that informs about problem
         * @param LineNumber Line where problem occurs
         * @param File File where problem occurs
         * @param InnerException Exception that was thrown before
         * @return new instance of ServerException class
         */
        ServerException(string ErrorMessage, int Line, string File, Exception* InnerException);

        /**
         * @return "ServerException"
         */
        virtual string GetType() const;
    };
}


#endif //CERVISEMESTRALKA_SERVEREXCEPTION_H
