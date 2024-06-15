#include<bits/stdc++.h>
using namespace std;

void printArr(int n, int arr[]) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << '\n';
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n; i++){
        cin >> arr[i];
    }

    // pushing maximum to the end.
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
        printArr(n, arr);       // optional, just to look at the structure of the array at every pass
    }

    cout << "Sorted array : ";
    printArr(n, arr);
}
