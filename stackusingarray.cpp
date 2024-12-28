// WRITE A C++ PROGRAM TO PERFORM STACK OPERATION USING ARRAY.
/*
This c++ program implements a stack data structure using an array. The program provides 
functions to perform basic stack operations such as push, pop, peek, isEmpty, and isFull.
*/
#include<iostream>
using namespace std;
class Stack {
    private:
    int top;
    int arr[10];
    int capacity;

    public:
    Stack(){
        top = -1;
        capacity = 10;
    }

    void push(int value){
        if(top >= capacity - 1){
            cout<<"Stack is full. Cannot push."<<value<<endl;
            return;
        }
        arr[++top] = value;
    }
    int pop(){
        if(top < 0){
            cout<<"Stack is empty. Cannot pop."<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top < 0){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top < 0;
    }

    void printStack(){
        cout<<"Stack elements: ";
        for(int i=0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack stack;
    int choice, value;

    while(true){
        cout<<"Stack operations: "<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Check if empty"<<endl;
        cout<<"5. Print stack"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"Enter value to push:";
                cin>>value;
                stack.push(value);
                break;
            }
            case 2:{
                value = stack.pop();
                if(value != -1){
                    cout<<"Popped value: "<<value<<endl;
                }
                break;
            }
            case 3:{
                value = stack.peek();
                if(value != -1){
                    cout<<"Top value: "<<value<<endl;
                }
                break;
            }
            case 4:{
                if(stack.isEmpty()){
                    cout<<"Stack is empty"<<endl;
                } else {
                    cout<<"Stack is not empty"<<endl;
                }
                break;
            }
            case 5: {
                stack.printStack();
                break;
            }
            case 6: {
                exit (0);
            }
            default:
            cout<<"Invalid choice. Please choose a valid option."<<endl;
        }
    }
    return 0;
}