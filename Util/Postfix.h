#ifndef SFML_CALCULATOR_POSTFIX_H
#define SFML_CALCULATOR_POSTFIX_H
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include "PostfixException.h"

/**
 * Utility class which allows for the evaluation of infix expressions.
 */
class Postfix {
public:
    ///////////////////////
    // Solution Functions
    ///////////////////////

    /**
     * Attempts to evaluate the passed infix expression. If an error occurs within the function,
     * an exception will be thrown.
     * @param infix_expression the expression to evaluate
     * @return
     */
    static double evaluate(const std::string &infix_expression);
    /**
     * Converts the infix expression into its postfix form using the Shunting Yard Algorithm.
     * @param infix_expression the expression to convert into postfix
     * @return the postfix version of the expression
     */
    static std::string infixToPostfix(const std::string &infix_expression);

private:
    static const char DEFAULT_PREV_TOKEN;
    /////////////////////////////
    // RPN and Helper Functions
    /////////////////////////////
    /**
     * Uses the Reverse Polish Notation algorithm to solve a postfix expression.
     * @param postfix_expression the expression (in postfix form) to solve
     * @return the result of the expression
     */
    static double RPN(const std::string &postfix_expression);
    /**
     * Helper function for the RPN() function.
     * Simply evaluates leftNum and rightNum depending on the context of {operation}.
     * @param leftNum the left number
     * @param rightNum the right number
     * @param operation the operation to occur between leftNum and rightNum
     * @return the result of the operation between leftNum and rightNum
     */
    static double eval(double leftNum, double rightNum, char operation);

    //////////////////////////////////////
    // infixToPostfix() Helper Functions
    //////////////////////////////////////
    /**
     * Checks if the {operatorToCompare} has a higher precedence.
     * @param operatorToCompare the operator to compare
     * @param topOperator the other operator, which is at the top of the stack
     * @return true if {operatorToCompare} has a higher precedence
     */
    static bool isHigherPrecedence(char operatorToCompare, char topOperator);
    /**
     * Handles the closing parentheses logic for the Shunting Yard Algorithm.
     * @param operators the current stack of operators
     * @param postfix the current state of the postfix queue (in this case std::string)
     */
    static void closingParenthesesLogic(std::stack<char> &operators, std::string &postfix);
    /**
     * Handles the logic for when a valid operator is encountered.
     * @param operators the current stack of operators
     * @param postfix the current state of the postfix queue (in this case std::string)
     * @param _operator the current operator
     * @param prevToken the character previous to the current operator
     */
    static void validOperatorLogic(std::stack<char> &operators, std::string &postfix, char _operator, char prevToken);
    /**
     * Handles the unary negation logic.
     * @param operators the current stack of operators
     * @param postfix the current state of the postfix queue (in this case std::string)
     * @param _operator the operator, usually '-'.
     */
    static void unaryMinusLogic(std::stack<char> &operators, std::string &postfix, char _operator);

    //////////////////////////////
    // General Helper Function(s)
    //////////////////////////////
    static bool isOperator(char c);
};

#endif //SFML_CALCULATOR_POSTFIX_H