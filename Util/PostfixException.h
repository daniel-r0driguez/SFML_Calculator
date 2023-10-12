#ifndef SFML_CALCULATOR_POSTFIXEXCEPTION_H
#define SFML_CALCULATOR_POSTFIXEXCEPTION_H
#include <exception>

class PostfixException : public std::exception {
private:
    const char* _message;
public:
    PostfixException();
    explicit PostfixException(const char* message);
    const char* what() const noexcept override;
};


#endif //SFML_CALCULATOR_POSTFIXEXCEPTION_H
