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
/**
 * Utility class which creates a new dynamically allocated CalculatorButton instance.
 * You can choose between:
 * (1) CalculatorCharButton
 * (2) CalculatorClearButton
 * (3) CalculatorEnterButton
 *
 * To choose between the three options, pass in the appropriate Button_Instance enum.
 */
class CalculatorButtonInstance {
public:
    /**
     * Returns a CalculatorButton instance depending on various parameters.
     * @param instanceType the requested Button_Instance
     * @param associatedTextBox the TextBox to link with the newly created button instance
     * @param associatedChar an optional char value if you request a Button_Instance::CHAR instance, otherwise the char is ignored
     * @param position the position to place the newly created CalculatorButton instance
     * @param btnSize the size to set to the newly created CalculatorButton instance
     * @return the request CalculatorButton instance, depending on the parameters passed
     */
    static CalculatorButton* getButtonInstance(Button_Instance instanceType, TextBox &associatedTextBox, char associatedChar = '\0', const sf::Vector2f &position = {0, 0}, const sf::Vector2f &btnSize = {10, 10});

private:
    //////////////////////
    // Helper Function(s)
    //////////////////////
    static Images::Image getCorrectImage(char c);
};

#endif //SFML_CALCULATOR_CALCULATORBUTTONINSTANCE_H