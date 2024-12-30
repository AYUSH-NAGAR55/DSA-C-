// WRITE A C++ PROGRAM TO IMPLEMENT BASIC OPERATIONS ON A CIRCULAR QUEUE.
/*
This c++ program implements a circular queue with basic operations like enqueue, dequeue and display.
it asks the user for the queue's capacity and provides a menu-driven interface to perform enqueue, dequeue
and display operations.
*/
#include<iostream>
using namespace std;

class CircularQueue {
    int*arr;
    int front, rear, size, capacity;

public: 
CircularQueue(int capacity){
    this->capacity=capacity;
    arr = new int[capacity];
    front = rear = size = 0;
}
CircularQueue(){
    delete[] arr;
}

void enqueue(int value){
    if(size == capacity){
        cout<<"Queue is full."<<endl;
        return;
    }
    rear = (rear+1) % capacity;
    arr[rear] = value;
    size++;
}

int dequeue(){
    if(size == 0){
        cout<<"Queue is empty."<<endl;
        return -1;
    }
    int value = arr[front];
    front = (front+1) % capacity;
    size--;
    return value;
}
void display(){
    if(size == 0){
        cout<<"Queue is empty."<<endl;
        return;
    }
    int temp = front;

    for(int i=0; i<size; i++){
        cout<<arr[temp]<<" ";
        temp = (temp + 1) % capacity;
    }
    cout<<endl;
}
};

int main(){
    int capacity;
    cout<<"Enter the capacity of the queue: ";
    cin>>capacity;

    CircularQueue q(capacity);

    int choice, value;

    do{
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1: {
                cout<<"Enter value to enqueue:";
                cin>>value;
                q.enqueue(value);
                break;
            }
            case 2:{
                value = q.dequeue();
                if(value != -1){
                    cout<<"Dequeued value: "<<value<<endl;
                }
                break;
            }
            case 3:{
                q.display();
                break;
            }
            case 4:{
                break;
            }
            default:
            cout<<"Invalid choice."<<endl;
        }
    }   while(choice != 4);
    return 0;
}
