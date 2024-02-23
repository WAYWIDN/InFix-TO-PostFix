#include<iostream>
#include<string>
#include"IsValid1.cpp"//Header File To Check Enterd Expression is Valid Or Not
#include"ConvertToPostFix1.cpp"//Header File to Convert Infix Expression into PostFix 
#include"EvaluatePostFix1.cpp"//Header File to Evaluate PostFix Expression

int main()
{
    string str;
    cout<<"\nEnter The Expression : ";
    cin>>str;

    if(IsValid(str)) 
    {
        cout<<"\nEntered Expression is Valid ";
        cout<<"\n\n";

        string Postfix = ConvertToPostfix(str);
        cout<<"\nPostFix of Entered Expression is : "<<Postfix;
        cout<<"\n\n";

        int value;
        value = EvaluatePostFix(Postfix);
        cout<<"\nValue : "<<value;

    }
    else cout<<"\nEntered Expression is Invalid"; 

    return 0;
}

