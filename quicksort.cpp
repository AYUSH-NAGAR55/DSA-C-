// WRITE A C++ PROGRAM TO SORT THE LIST OF INTEGERS USING Quick SORT AND ANALYSE THE TIME COMPLEXITY.
/*
The program first asks the user to input the size of array.
Then, it asks the user to input the elements of the array.
The program then prints the original array.
The quick sort function is called to sort the array using quick sort.
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

// function to partition the array
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// function to perform quick sort
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(arr, 0 , n-1);

    cout<<"Sorted Array: ";
    printArray(arr, n);

    delete arr;
    return 0;
}