#include<bits/stdc++.h>
using namespace std;

int RandomizedPartition(vector<int> &a, int p, int r){
    srand(time(0));                         // Use current time as seed for random generator
    int i = p + rand() % (r - p + 1);       // random index in [p, r + 1) to be taken as pivot.
    int x = a[i];                           // pivot value is x
    swap(a[i], a[r]);                       // sending the pivot at the last(as rest can algorithm can work just the same)
    // cout << "Pivot is : " << a[r] << '\n';
    i = p - 1;
    for(int j = p; j <= r - 1; j++){
        if(a[j] <= x){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void RandomizedQuickSort(vector<int> &a, int p, int r){
    if(p >= r){
        return;
    }
    int q = RandomizedPartition(a, p, r);             // index of pivot
    RandomizedQuickSort(a, p, q - 1);
    RandomizedQuickSort(a, q + 1, r);
}

int main()
{
    int n = 8;
    vector<int>a = {2, 1, 4, 5, 3, 8, 6, 7};
    RandomizedQuickSort(a, 0, 7);
    for(int i = 0; i < 8; i++){
        cout << a[i] << " ";
    }
    return 0;
}