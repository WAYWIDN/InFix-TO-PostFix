#include<iostream>
#include<string>
#include"IsValid.cpp"//Header File To Check Enterd Expression is Valid Or Not
#include"ConvertToPostFix.cpp"//Header File to Convert Infix Expression into PostFix 
#include"EvaluatePostFix.cpp"//Header File to Evaluate PostFix Expression

int main()
{
    string str;
    cout<<"\nEnter The Expression : ";
    cin>>str;

    if(IsValid(str)) 
    {
        cout<<"Entered Expression is Valid ";

        string Postfix = ConvertToPostfix(str);
        cout<<"\nPostFix of Entered Expression is : "<<Postfix;

        int value;
        value = EvaluatePostFix(Postfix);
        cout<<"\nValue : "<<value;

    }
    else cout<<"\nEntered Expression is Invalid"; 

    return 0;
}

