#ifndef SFML_CALCULATOR_KEYCHAR_H
#define SFML_CALCULATOR_KEYCHAR_H

class KeyChar {
private:
    char _lowercase;
    char _uppercase;

public:
    KeyChar();
    KeyChar(char lowercaseForm, char uppercaseForm);

    char getUppercase() const;
    char getLowercase() const;
    void setUppercase(char uppercaseForm);
    void serLowercase(char lowercaseForm);
};

#endif //SFML_CALCULATOR_KEYCHAR_H