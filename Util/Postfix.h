#ifndef SFML_CALCULATOR_POSTFIX_H
#define SFML_CALCULATOR_POSTFIX_H
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include "PostfixException.h"

class Postfix {
public:
    static std::string infixToPostfix(const std::string &infix_expression);
    static double evaluate(const std::string &infix_expression);

private:
    static const char DEFAULT_PREV_TOKEN;
    static double RPN(const std::string &postfix_expression);
    static double eval(double leftNum, double rightNum, char operation);
    static bool isOperator(char c);
    static bool isHigherPrecedence(char operatorToCompare, char topOperator);
    static void closingParenthesesLogic(std::stack<char> &operators, std::string &postfix);
    static void validOperatorLogic(std::stack<char> &operators, std::string &postfix, char _operator, char prevToken);
    static void unaryMinusLogic(std::stack<char> &operators, std::string &postfix, char _operator);
};

#endif //SFML_CALCULATOR_POSTFIX_H