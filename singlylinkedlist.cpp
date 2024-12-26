// WRITE A C++ PROGRAM TO INSERT AND DELETE IN A SINGLY LINKED LIST.
/* 
1. The program creates a singly linked list with functions to insert nodes, delete nodes, and print the list.
2. the user is presented with a menu to choose from the available options.
3. based on the users choice, the program perform the corressponding action.
*/
#include<iostream>
using namespace std;

// node structure
struct Node{
    int data;
    Node*next;
};

//  linked list class
class LinkedList{
public:
    Node*head;

    LinkedList(){
        head = NULL;
    }

// insert node at the end
void insert(int data){
    Node*newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else {
        Node*temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

// delete node by value
void deleteNode(int data){
    if(head == NULL) return;

    if(head -> data == data){
        Node*temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    Node*temp = head;
    while(temp -> next != NULL){
        if(temp ->next->data == data){
            Node*nodeToDelete = temp -> next;
            temp -> next = temp -> next -> next;
            delete nodeToDelete;
            return;
        }
        temp = temp -> next;
    }
}

// print linked list
void printList(){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
  }
};

int main(){
    LinkedList list;

    while(true){
        cout<<"1. Insert node"<<endl;
        cout<<"2. Delete node"<<endl;
        cout<<"3. Print list"<<endl;
        cout<<"4. Exit"<<endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                int data;
                cout<<"Enter data to insert:";
                cin>>data;
                list.insert(data);
                break;
            }
            case 2:{
                int data;
                cout<<"Enter data to delete:";
                cin>>data;
                list.deleteNode(data);
                break;
            }
            case 3:{
                list.printList();
                break;
            }
            case 4:{
                return 0;
            }
            default:
            cout<<"Invalid choice. Please choose a valid option."<<endl;
        }
    }
    return 0;
}

