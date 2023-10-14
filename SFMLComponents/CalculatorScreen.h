#ifndef SFML_CALCULATOR_CALCULATORSCREEN_H
#define SFML_CALCULATOR_CALCULATORSCREEN_H
#include "Typing.h"
#include "../Util/Postfix.h"

class CalculatorScreen : public Typing {
public:
    CalculatorScreen();
    explicit CalculatorScreen(int characterSize);
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

private:
    void callPostFix();

};


#endif //SFML_CALCULATOR_CALCULATORSCREEN_H
