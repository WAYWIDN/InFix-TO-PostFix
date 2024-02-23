#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <iomanip> 
using namespace std;

//---> Function to Display Stack 
void DisplayStack(stack<char> stk)
{
    stack<char> tempStack; // Temporary stack to store elements in reverse order

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

//---> Function to convert an infix expression to postfix (Assumed that Entered Expression is valid )
string ConvertToPostfix(string infix)
{
    string postfix = ""; // Initialize an empty string to store postfix expression
    stack<char> stk;     // Initialize a stack to hold operators

    cout << "_______________________________________________" << endl;
    cout << "| Symbol  | Postfix String   | Stack        " << endl;
    cout << "_______________________________________________" << endl;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        cout << "| " << setw(7) << ch << " |"; // Display The Current Symbol

        //---> If the character is an operand, add it to the postfix expression
        if (isalnum(ch))
        {
            postfix += ch;
            cout << setw(18) << postfix << "|";
            DisplayStack(stk);
        }

        //---> If the character is an opening parenthesis, push it onto the stack
        else if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
            cout << setw(18) << postfix << "|";
            DisplayStack(stk);
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
            cout << setw(18) << postfix << "|";
            DisplayStack(stk);
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
            cout << setw(18) << postfix << "|";
            DisplayStack(stk);
        }
        cout << endl;
    }

    //--->Pop remaining operators from the stack and add them to the postfix expression
    while (!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }

    return postfix; // Return the postfix expression
}

