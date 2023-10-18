#ifndef SFML_CALCULATOR_KEYCHAR_H
#define SFML_CALCULATOR_KEYCHAR_H

/**
 * Simple wrapper class which can represent a key on the Keyboard (both uppercase and lowercase versions)
 */
class KeyChar {
private:
    char _lowercase;
    char _uppercase;

public:
    ////////////////////
    // Constructors
    ////////////////////
    KeyChar();
    KeyChar(char lowercaseForm, char uppercaseForm);

    ////////////////////////
    // Character Functions
    ////////////////////////
    /**
     * Returns the uppercase character.
     * @return the uppercase character assigned to this object
     */
    char getUppercase() const;
    /**
     * Returns the lowercase character.
     * @return the lowercase character assigned to this object
     */
    char getLowercase() const;
    /**
     * Assigns the uppercase character.
     * @param uppercaseForm the uppercase character you want associated with this object
     */
    void setUppercase(char uppercaseForm);
    /**
     * Assigns the lowercase character.
     * @param lowercaseForm the lowercase character you want associated with this object
     */
    void serLowercase(char lowercaseForm);
};

#endif //SFML_CALCULATOR_KEYCHAR_H