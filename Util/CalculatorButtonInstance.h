#ifndef SFML_CALCULATOR_CALCULATORBUTTONINSTANCE_H
#define SFML_CALCULATOR_CALCULATORBUTTONINSTANCE_H
#include "Images.h"
#include "../SFMLComponents/TextBox.h"
#include "../SFMLComponents/CalculatorButton.h"
#include "../SFMLComponents/CalculatorCharButton.h"
#include "../SFMLComponents/CalculatorClearButton.h"
#include "../SFMLComponents/CalculatorEnterButton.h"

enum Button_Instance {CHAR, CLEAR, ENTER,
                      BUTTON_INSTANCE_COUNT};

class CalculatorButtonInstance {
public:
    static CalculatorButton* getButtonInstance(Button_Instance instanceType, TextBox &associatedTextBox, char associatedChar = '\0', const sf::Vector2f &position = {0, 0}, const sf::Vector2f &btnSize = {10, 10});

private:
    static Images::Image getCorrectImage(char c);
};


#endif //SFML_CALCULATOR_CALCULATORBUTTONINSTANCE_H
