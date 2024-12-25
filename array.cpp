// WRITE A PROGRAM IN C++ TO PERFORM INSERTION AND DELETION IN AN ARRAY.
#include<iostream>
using namespace std;

class Array {
    int * arr;
    int size;
    int capacity;

public:
   Array(int cap){
    arr = new int[cap];
    size = 0;
    capacity = cap;
   }

//    insert an element at the end
void insert(int element){
    if(size < capacity){
        arr[size] = element;
        size++;
        cout<<"Element inserted successfully."<<endl;
    }
    else {
        cout<<"Array is full. Cannot insert more elements."<<endl;
    }
}

// insert an element at specific position
void insertAtPosition(int element, int position){
    if(position < 0 || position > size){
        cout<<"Invalid position."<<endl;
        return;
    }
    if(size < capacity){
        for(int i=size; i>position;i--){
            arr[i] = arr[i-1];
        }
        arr[position] = element;
        size++;
        cout<<"Element inserted successfully."<<endl;
    }
    else {
        cout<<"Array is full. Cannot insert more element."<<endl;
    }
}
// delete an element from the end
void deleteelement(){
    if(size > 0){
        size--;
        cout<<"Element deleted successfully."<<endl;
    }
    else {
        cout<<"Array is empty. Cannot delete more element."<<endl;
    }
}

//  delete an element from the specific position
void deleteAtPosition(int position){
    if(position < 0 || position >= size){
        cout<<"Invalid posiiton."<<endl;
        return;
    }
    for(int i=position;i<size;i++){
        arr[i] = arr[i+1];
    }
    size--;
    cout<<"Element deleted successfully."<<endl;
}

// print the array
void printArray(){
    cout<<"Array element:";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};

int main(){
    int capacity;
    cout<<"Enter the capacity of the array:";
    cin>>capacity;

    Array arr(capacity);
    
    while(true){
        cout<<"1. Insert an element at the end"<<endl;
        cout<<"2. Insert an element at the specific position"<<endl;
        cout<<"3. Delete an element from the end"<<endl;
        cout<<"4. Delete an element from the specific position"<<endl;
        cout<<"5. Print the array"<<endl;
        cout<<"6. Exit"<<endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: {
                int element;
                cout<<"Enter the element to insert:";
                cin>>element;
                arr.insert(element);
                break;
            }
            case 2: {
                int element, position;
                cout<<"Enter the element to insert:";
                cin>>element;
                arr.insert(element);
                cout<<"Enter the position to insert:";
                cin>>position;
                arr.insertAtPosition(element, position);
                break;
            }
            case 3: {
                arr.deleteelement();
                break;
            }
            case 4: {
                int position;
                cout<<"Enter the position to delete:";
                cin>>position;
                arr.deleteAtPosition(position);
                break;
            }
            case 5: {
                arr.printArray();
                break;
            }
            case 6: {
                return 0;
            }
            default:
              cout<<"Invalid choice. please choose a valid option."<<endl;

        }
    }
return 0;
}

// OUTPUT:
/* 1. asks the user for the array capacity.
2. provides a menu to:
   a. insert element at the end or at the specific position.
   b. delete elements from the end or at a specific position.
   c. print the array.
3. continues to prompt the user for input until they choose to exit.  */