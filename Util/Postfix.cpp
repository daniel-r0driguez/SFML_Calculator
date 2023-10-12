#include "Postfix.h"
#include <iostream>

const char Postfix::DEFAULT_PREV_TOKEN = 'S';

double Postfix::evaluate(const std::string &infix_expression)
{
    try
    {
        return RPN(infixToPostfix(infix_expression));
    }
    catch (std::exception &e)
    {
        throw e;
    }
}

std::string Postfix::infixToPostfix(const std::string &infix_expression)
{
    // Step 1. Create a stack.
    std::stack<char> operators;
    // Step 2. Create a queue
    std::string postfix;

    // Step 3. Create a temp string variable to represent numbers.
    std::string temp_num;

    char prevToken = Postfix::DEFAULT_PREV_TOKEN;

    // Step 4. Iterate through each character in the infix_expression.
    for (char c : infix_expression)
    {
        // Step 5. Check if c is a digit or operator.
        if (std::isdigit(c) || c == '.')
        {
            // If c is a digit, push this digit to temp_num;
            temp_num.push_back(c);
        }
        else if (isOperator(c))
        {
            // Otherwise if c is an operator, push temp_num into postfix.
            (!temp_num.empty()) ? postfix.insert(postfix.size(), temp_num + " ") : "";
            // Clear the contents of temp_num for the next number.
            temp_num.clear();

            // Now that we have inserted the number, it is time to decide what to do with the operator.

            // If c is a closing parentheses...
            if (c == ')')
            {
                closingParenthesesLogic(operators, postfix);
            }
            // Else that means we are dealing with a valid operator that can be pushed to the stack.
            else
            {
                validOperatorLogic(operators, postfix, c, prevToken);
            }
        }
        else if (c != ' ')
        {
            throw PostfixException();
        }

        if (std::isdigit(c) || isOperator(c))
        {
            prevToken = c;
        }
    }

    // Step 6. Once we run out of string to traverse...
    // ...Ensure no number is left behind. The reason is that the last number is not automatically pushed into postfix
    // in the loop since there is no operator after it.
    // NOTE: In the loop above, numbers are only pushed into postfix until an operator is found after it.
    (!temp_num.empty()) ? postfix.insert(postfix.size(), temp_num) : "";

    // Step 7. Then ensure no operators are left behind as well.
    while (!operators.empty())
    {
        postfix.push_back(operators.top());
        operators.pop();
    }

    // Step 8. Return the final postfix expression.
    return postfix;
}

void Postfix::closingParenthesesLogic(std::stack<char> &operators, std::string &postfix)
{
    // Keep pushing to postfix and popping till we hit a '(' at the top.
    while (operators.top() != '(')
    {
        postfix.push_back(operators.top());
        operators.pop();
    }
    // Then pop off the '('.
    operators.pop();
}

void Postfix::validOperatorLogic(std::stack<char> &operators, std::string &postfix, char _operator, char prevToken)
{
    if ((_operator == '-' && isOperator(prevToken)) || (_operator == '-' && prevToken == DEFAULT_PREV_TOKEN))
    {
        unaryMinusLogic(operators, postfix, _operator);
    }
    // If the stack is empty or _operator has a higher precedence than operators.top()...
    else if (operators.empty() || isHigherPrecedence(_operator, operators.top()))
    {
        // ...push _operator to the stack
        operators.push(_operator);
    }
    else
    {
        // ...otherwise push to queue and pop the stack until the stack is empty or _operator has a higher precedence
        // than operators.top()
        while (!operators.empty() && !isHigherPrecedence(_operator, operators.top()))
        {
            postfix.push_back(operators.top());
            operators.pop();
        }
        // Once the loop breaks, push _operator to the stack
        operators.push(_operator);
    }
}

void Postfix::unaryMinusLogic(std::stack<char> &operators, std::string &postfix, char _operator)
{
    // TODO fix the unary negation sign.
    postfix.insert(postfix.size(), "0 ");
    operators.push(_operator);
}

double Postfix::RPN(const std::string &postfix_expression)
{
    std::stack<double> nums;
    std::string tempNum;

    for (char c : postfix_expression)
    {
        // If c is a digit, push it to tempNum.
        if (std::isdigit(c) || c == '.')
        {
            tempNum.push_back(c);
        }
        // Otherwise c is most likely a delimiter which separates numbers from each other.
        else
        {
            // Push the numerical value of tempNum to nums.
            (!tempNum.empty()) ? nums.push(std::stod(tempNum)) : void();
            // Clear tempNum for the next number.
            tempNum.clear();
        }

        // If c is an operator, then evaluate the top two items in num using the operator c.
        if (isOperator(c))
        {
            double rightNum = (!nums.empty()) ? nums.top() : 0;
            (!nums.empty()) ? nums.pop() : void();
            double leftNum = (!nums.empty()) ? nums.top() : 0;
            (!nums.empty()) ? nums.pop() : void();

            nums.push(eval(leftNum, rightNum, c));
            std::cout << leftNum << ' ' << c << ' ' << rightNum << " = " << nums.top() << '\n';
        }
    }
    return nums.top();
}

double Postfix::eval(double leftNum, double rightNum, char operation)
{
    switch (operation)
    {
        case '+':
            return leftNum + rightNum;
        case '-':
            return leftNum - rightNum;
        case '*':
            return leftNum * rightNum;
        case '/':
            return leftNum / rightNum;
        case '^':
            return std::pow(leftNum, rightNum);
        default:
            throw "Invalid operator!";
    }
}

bool Postfix::isOperator(char c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '^':
            return true;
        default: return false;
    }
}

bool Postfix::isHigherPrecedence(char operatorToCompare, char topOperator)
{
    // Return true since any operator can go on top of a '(' operator.
    if (topOperator == '(')
    {
        return true;
    }

    // Otherwise, compare the operators.
    switch (operatorToCompare)
    {
        case '^':
            return (topOperator != '^');
        case '(':
            return true;
        case '*':
        case '/':
            return (topOperator == '+' || topOperator == '-');
        default:
            return false;
    }
}