#include<bits/stdc++.h>
using namespace std;
// stable
// TC : O(nlogn), worst : O(nlogn)
// SC : O(n)

void MERGE(vector<int> &a, int p, int q, int r){
    vector<int> b = a;          // auxillary array for temporary storage
    int i = p, j = q + 1, k = p;
    while(i <= q || j <= r){    // merging two subarrays
        if(j == r + 1 || (i <= q && a[i] <= a[j])){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    a = b;
    return;
}

void MergeSort(vector<int> &a, int p, int r){
    if(p >= r){
        return;
    }
    // if p < r :
    int q = (p + r) / 2;      // q = p + (r - p) / 2;
    MergeSort(a, p, q);
    MergeSort(a, q + 1, r);
    MERGE(a, p, q, r);
}

int main()
{
    int n = 8;
    vector<int>a = {2, 1, 4, 5, 3, 8, 6, 7};
    MergeSort(a, 0, 7);
    for(int i = 0; i < 8; i++){
        cout << a[i] << " ";
    }
    return 0;
}
