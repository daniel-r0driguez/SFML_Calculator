#include "PostfixException.h"

PostfixException::PostfixException()
: PostfixException("Error in PostFix. Expression could not be evaluated.")
{}

PostfixException::PostfixException(const char *message)
{
    this->_message = message;
}

const char *PostfixException::what() const noexcept
{
    return this->_message;
}