#ifndef SFML_CALCULATOR_POSTFIXEXCEPTION_H
#define SFML_CALCULATOR_POSTFIXEXCEPTION_H
#include <exception>

/**
 * Simple exception for the PostFix class.
 */
class PostfixException : public std::exception {
private:
    const char* _message;
public:
    //////////////////
    // Constructor
    //////////////////
    PostfixException();
    explicit PostfixException(const char* message);

    ////////////////////
    // What() function
    ////////////////////
    /**
     * Returns the error message that the exception contains.
     * @return the error message that the exception contains
     */
    const char* what() const noexcept override;
};

#endif //SFML_CALCULATOR_POSTFIXEXCEPTION_H