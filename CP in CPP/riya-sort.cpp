#include <bits/stdc++.h>
using namespace std;

int howyoufeel[6] = {24, 5, 2002, 9, 12, 2001};
vector<int>riyafeelsbad = {3,2,1,5,3,6};

void print(int a[], int n) {
    cout << "The array is : ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void reset(int a[], int n) {
    a[0] = 2;
    a[1] = 5;
    a[2] = 1;
    a[3] = 4;
    a[4] = 3;
    a[5] = -2;
}

int main() {
    int n = 6;
    int a[n] = {2,5,1,4,3,-2};
    sort(a, a + n); // n is size of array

    // BUBBLE SORT
    // {0,1,2,3,4,5}  => INDEX
    // [2,5,1,4,3,-2] => ORIGINAL ARRAY
            // [2,5,1,4,3,-2]
            // [2,1,5,4,3,-2]
            // [2,1,4,5,3,-2]
            // [2,1,4,3,5,-2]
            // [2,1,4,3,-2,5]
    // [2,1,4,3,-2,5] => AFTER FIRST PASS
    // [1,2,3,-2,4,5] => AFTER SECOND PASS
    // [1,2,-2,3,4,5]
    // [1,-2,2,3,4,5]
    // [-2,1,2,3,4,5] => SORTED ARRAY
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            // check for indices j and j+1 and decide to swap or not
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    print(a, n);
    reset(a, n);
    // TC = O(n2)
    // SC = O(1)

    // SELECTION SORT => Find minimum element from [i...n-1] and swap it with index i
    // {0,1,2,3,4,5}  => INDEX
    // [2,5,1,4,3,-2] => ORIGINAL ARRAY
    // [-2,5,1,4,3,2] => AFTER FIRST PASS
    // [-2,1,5,4,3,2] => AFTER SECOND PASS
    // [-2,1,2,4,3,5]
    // [-2,1,2,3,4,5]
    // [-2,1,2,3,4,5] => SORTED ARRAY
    for(int i = 0; i < n; i++) {
        int mini = INT_MAX, mini_ind;
        for(int j = i; j < n; j++) {
            if(mini > a[j]) {
                mini = a[j];
                mini_ind = j;
            }
        }
        swap(a[i], a[mini_ind]);
    }
    print(a, n);
    reset(a, n);

    // INSERTION SORT   => Consider a sorted segment [0...i] then insert a[i+1] in correct position in the sorted segement [0...i+1]
    // {0,1,2,3,4,5}  => INDEX
    // [2,5,1,4,3,-2] => ORIGINAL ARRAY
    // [2,5,1,4,3,-2]
    // [1,2,5,4,3,-2]
    // [1,2,4,5,3,-2]
    // [1,2,3,4,5,-2]
    // [-2,1,2,3,4,5]
    for(int i = 1; i < n; i++) {
        int x = a[i];
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(a[j] < a[i]) {
                break;
            }
            a[j + 1] = a[j];
        }
        swap(a[i], x);
    }
    print(a, n);
    reset(a, n);

    // MERGE SORT


    // QUICK SORT

    return 0;
}