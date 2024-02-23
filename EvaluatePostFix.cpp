#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include "IsValid.cpp"//Header File To Check Enterd Expression is Valid Or Not
using namespace std;


//--->Function to evaluate a postfix expression

int EvaluatePostFix(string postfix)
{

    stack<int> stk; // Initialize a stack to hold operands

    int op1, op2, value;
    for (int i = 0; i < postfix.size(); i++)
    {

        if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '^')
        {
            stk.push(postfix[i] - '0'); // Convert character to integer and push into the stack
        }

        //--->If the symbol is an operator

        else
        {
            //--->Pop the top two operands from the stack

            op2 = (int)stk.top();
            stk.pop();
            op1 = (int)stk.top();
            stk.pop();

            //--->Perform the operation based on the operator
            if (postfix[i] == '+')
                value = op1 + op2;
            else if (postfix[i] == '-')
                value = op1 - op2;
            else if (postfix[i] == '*')
                value = op1 * op2;
            else if (postfix[i] == '/')
                value = op1 / op2;
            else if (postfix[i] == '^')
                value = pow(op1, op2);

            //--->Push the result back onto the stack
            stk.push(value);
        }
    }

    return stk.top(); // Return the final result
}

