#include "KeyChar.h"

KeyChar::KeyChar()
: KeyChar(' ', ' ')
{}

KeyChar::KeyChar(char lowercaseForm, char uppercaseForm)
{
    this->_lowercase = lowercaseForm;
    this->_uppercase = uppercaseForm;
}

char KeyChar::getUppercase() const
{
    return this->_uppercase;
}

char KeyChar::getLowercase() const
{
    return this->_lowercase;
}

void KeyChar::setUppercase(char uppercaseForm)
{
    this->_uppercase = uppercaseForm;
}

void KeyChar::serLowercase(char lowercaseForm)
{
    this->_lowercase = lowercaseForm;
}