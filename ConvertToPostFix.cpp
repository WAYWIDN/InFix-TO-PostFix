#include <iostream>
#include <stack>
#include <string>
#include "IsValid.cpp" //Header File To Check Enterd Expression is Valid Or Not
using namespace std;

//---> Function to determine the precedence of operators

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1; // Return -1 for invalid operators
}

//---> Function to check if a character is an operator

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

//---> Function to convert an infix expression to postfix(Assumed that Entered Expression is valid )

string ConvertToPostfix(string infix)
{
    if (IsValid(infix)) // If The Entered Expression is Valid Then Conevert it to PostFix
    {
        string postfix = ""; // Initialize an empty string to store postfix expression
        stack<char> stk;     // Initialize a stack to hold operators

        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i];

            //---> If the character is an operand, add it to the postfix expression
            if (isalnum(ch))
            {
                postfix += ch;
            }

            //---> If the character is an opening parenthesis, push it onto the stack
            else if (ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }

            //---> If the character is a closing parenthesis, pop operators from the stack until the corresponding opening parenthesis is found

            else if (ch == ')' || ch == '}' || ch == ']')
            {
                char corresponding_open;
                if (ch == ')')
                    corresponding_open = '(';
                else if (ch == '}')
                    corresponding_open = '{';
                else if (ch == ']')
                    corresponding_open = '[';

                while (!stk.empty() && stk.top() != corresponding_open)
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.pop(); // Pop the corresponding opening parenthesis
            }

            //--->If the character is an operator, pop operators from the stack until an operator with lower precedence or an opening parenthesis is encountered

            else if (isOperator(ch))
            {
                while (!stk.empty() && precedence(stk.top()) >= precedence(ch))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
        }

        //--->Pop remaining operators from the stack and add them to the postfix expression

        while (!stk.empty())
        {
            postfix += stk.top();
            stk.pop();
        }

        return postfix; // Return the postfix expression
    }

    else
        return "Invalid Infix Expression to Convert into Postfix";
}