#include<bits/stdc++.h>
using namespace std;

// not stable
// TC : O(nlogn), worst : O(n2)
// SC : O(logn), worst : O(n)

// int Partition(vector<int> &a, int p, int r){
//     int x = a[r];           // last element as pivot
//     cout << "Pivot is : " << a[r] << '\n';
//     int i = p - 1;
//     for(int j = p; j <= r - 1; j++){
//         if(a[j] <= x){
//             i++;
//             swap(a[j], a[i]);
//         }
//     }
//     swap(a[i + 1], a[r]);
//     return i + 1;
// }

int Partition(vector<int> &a, int p, int r){
    int x = a[p];           // first element as pivot
    swap(a[p], a[r]);       // sending the pivot at the last(as rest can algorithm can work just the same)
    // cout << "Pivot is : " << a[r] << '\n';
    int i = p - 1;
    for(int j = p; j <= r - 1; j++){
        if(a[j] <= x){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void QuickSort(vector<int> &a, int p, int r){
    if(p >= r){
        return;
    }
    int q = Partition(a, p, r);             // index of pivot
    QuickSort(a, p, q - 1);
    QuickSort(a, q + 1, r);
}

int main()
{
    int n = 8;
    vector<int>a = {2, 1, 4, 5, 3, 8, 6, 7};
    QuickSort(a, 0, 7);
    for(int i = 0; i < 8; i++){
        cout << a[i] << " ";
    }
    return 0;
}