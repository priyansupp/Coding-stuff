#include<iostream>
using namespace std;

void printArr(int n, int arr[]) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << '\n';
    return;
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];

    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    //insertionSort
    int key,j;
    for(i=1;i<n;i++){
        key=arr[i];             // element to be inserted.
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printArr(n, arr);       // optional, it is just to see the structure of array while the algo is in flow
    }
    
    cout << "Sorted array : ";
    printArr(n, arr);
}
