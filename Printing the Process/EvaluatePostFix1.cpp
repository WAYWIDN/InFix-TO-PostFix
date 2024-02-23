#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

//---> Function to display the contents of a stack

void DisplayStack(stack<int> stk)
{
    stack<int> tempStack; // Temporary stack to store elements in reverse order

    // Transfer elements from original stack to temporary stack
    while (!stk.empty())
    {
        tempStack.push(stk.top());
        stk.pop();
    }

    // Print elements from temporary stack (which are in reverse order)
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
}

//--->Function to evaluate a postfix expression

int EvaluatePostFix(string str)
{
    stack<int> stk; // Initialize a stack to hold operands

    cout << "______________________________________________________" << endl;
    cout << "| Symbol | Operand1 | Operand2 |  value  |   Stack   |" << endl;
    cout << "______________________________________________________" << endl;

    int op1, op2, value;
    op1 = -1; // Initialize op1 to -1 (used for display purposes untill first Operator Encounter )

    for (int i = 0; i < str.size(); i++)
    {
        cout << "    " << str[i] << "    "; // Print the current symbol

        if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^')
        {
            stk.push(str[i] - '0'); // Convert character to integer and push into the stack

            if (op1 == -1) // If it's the first operand
            {
                cout << "                                   ";
                DisplayStack(stk); // Display the stack
            }
            else // If it's not the first operand
            {
                cout << "    " << op1 << "      ";     // Print Operand1
                cout << "      " << op2 << "    ";     // Print Operand2
                cout << "    " << value << "        "; // Print the result value
                DisplayStack(stk);                     // Display the stack
            }
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
            if (str[i] == '+')
                value = op1 + op2;
            else if (str[i] == '-')
                value = op1 - op2;
            else if (str[i] == '*')
                value = op1 * op2;
            else if (str[i] == '/')
                value = op1 / op2;
            else if (str[i] == '^')
                value = pow(op1, op2);

            //--->Push the result back onto the stack
            stk.push(value);

            //--->Display the current operation and the stack
            cout << "    " << op1 << "      ";
            cout << "      " << op2 << "    ";
            cout << "    " << value << "        ";
            DisplayStack(stk);
        }

        cout << endl;
    }

    return stk.top(); // Return the final result
}

