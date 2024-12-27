//  WRITE A C++ PROGRAM TO PERFORM INSERTION AND DELETION IN DOUBLY LINKED LIST.
/*
1. this program creates a doubly linked list and provides options to insert nodes at the beginning and end, delete nodes
   from the beginning and end, and print the list.
2. the user is presented with a menu to choose from the available options.
3. based on the user's choice, the program performs the corressponding action.
*/
#include<iostream>
using namespace std;

// node structure
struct Node{
    int data;
    Node*next;
    Node*prev;
};

// doubly linked list class
class DoublyLinkedList{
public:
   Node*head;

   DoublyLinkedList(){
    head = NULL;
   }

//    insert node at beg
void insertAtBeginning(int data){
    Node*newNode = new Node();
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(head == NULL){
        head = newNode;
    } else {
        newNode->next=head;
        head->prev=newNode;
        head = newNode;
    }
}

// insert node at the end
void insertAtEnd(int data){
    Node*newNode = new Node();
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(head == NULL){
        head = newNode;
    } else {
        Node*temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

// delete node from the beg
void deleteFromBeginning(){
    if(head==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    Node*temp = head;
    head = head->next;

    if(head != NULL){
        head->prev=NULL;
    }
    delete temp;
}

// delete node from the end
void deleteFromEnd(){
    if(head==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    Node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    delete temp;
}

// print doubly linked list
void printList(){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
 }
};

int main(){
    DoublyLinkedList list;

    while(true){
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Delete from beginning"<<endl;
        cout<<"4. Delete from end"<<endl;
        cout<<"5. Print list"<<endl;
        cout<<"6. Exit"<<endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                int data;
                cout<<"Enter data to insert:";
                cin>>data;
                list.insertAtBeginning(data);
                break;
            }
            case 2:{
                int data;
                cout<<"Enter data to insert:";
                cin>>data;
                list.insertAtEnd(data);
                break;
            }
            case 3:{
                list.deleteFromBeginning();
                break;
            }
            case 4:{
                list.deleteFromEnd();
                break;
            }
            case 5: {
                list.printList();
                break;
            }
            case 6: {
                return 0;
            }
            default:
            cout<<"Invalid choice. Please choose a valid option."<<endl;
        }
    }
    return 0;
}