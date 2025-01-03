// WRITE A C++ PROGRAM TO SORT THE LIST OF INTEGERS USING BUBBLE SORT AND ANALYSE THE TIME COMPLEXITY.
/*
The program first asks the user to input the number of elements in the array.
Then, it asks the user to input the elements of the array.
The program then prints the original array.
The bubble sort function is called to sort the array using bubble sort.
The program then prints the sorted array.
*/
#include<iostream>
using namespace std;

// function to swap two elements
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//  function to perform bubble sort
void bubbleSort(int arr[], int n){
    for(int i=0; i<(n-1); i++){
        for(int j = 0; j< (n-i); j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// function to print the array
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int *arr = new int[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout<<"Sorted Array: ";
    printArray(arr, n);

    delete arr;
    return 0;
}