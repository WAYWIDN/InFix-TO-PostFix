#ifndef IsValid_cpp
#define IsValid_cpp

#include <iostream>
#include <stack>
#include <string>
    using namespace std;

//--->Function to check if the parentheses in the string are valid

bool IsValid(string str)
{
    stack<char> stk; // Create a stack to store opening parentheses encountered

    for (int i = 0; i < str.size(); i++)
    {
        //---> If the character is an opening parenthesis, push it onto the stack

        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stk.push(str[i]);
        }

        //---> If the character is a closing parenthesis

        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            //---> If the stack is empty, there's no corresponding opening parenthesis, so return false

            if (stk.empty())
            {
                return false;
            }

            else
            {
                char top = stk.top(); // Get the top element of the stack
                stk.pop(); // Pop the top element from the stack
                
                //---> Check if the closing parenthesis matches the last opening parenthesis on the stack

                if ((str[i] == ')' && top != '(') ||
                    (str[i] == ']' && top != '[') ||
                    (str[i] == '}' && top != '{'))
                {
                    return false; // If there's a mismatch, return false
                }
            }
        }
    }

    // If the stack is empty at the end, all parentheses are matched correctly, return true
    return stk.empty();
}

#endif