// WRITE A C++ PROGRAM TO CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION USING STACK.
/*
This program converts the infix expression to postfix expression using a stack. 
it takes an infix expression as input from the user, applies the rules of operand precedence,
and outputs the equivalent postfix expression.
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// function to check if the charater is an operand
bool isOperand(char c){
    return(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// function to check the precedence of an operator
int precendence(char c){
    if(c == '+' || c == '-'){
        return 1;
    } else if (c == '*' || c == '/'){
        return 2;
    } else if (c == '^'){
        return 3;
    } else {
        return 0;
    }
}

// function to convert infix to postfix
string infixToPostfix(const string& infix){
    stack<char>stack;
    string postfix = " ";

    for(char c : infix){
        if(isOperand(c)){
            postfix += c;
        } else if(c == '('){
            stack.push(c);
        } else if(c == ')'){
            while(stack.top() != '('){
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();    // remove the '('
        } else {
            while (!stack.empty() && precendence(c) <= precendence(stack.top())){
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while(!stack.empty()){
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout<<"Enter an infix expression: ";
    cin>>infix;

    string postfix = infixToPostfix(infix);
    cout<<"Postfix expression:"<<postfix<<endl;

    return 0;
}