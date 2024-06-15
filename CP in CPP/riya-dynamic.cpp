#include <bits/stdc++.h>
using namespace std;

// RAM -> STACK(limited) + HEAP(more than limited)

class ABC{};


int main() {

    int x = 1;      // x is on stack
    ABC abc;        // abc is an object of class ABC on stack
    int arr[4];      // ar is on stack
    // arr[1];

    int *a = &x;    // a is on stack

    // HEAP ALLOCATION

    int *y = (int*)malloc(sizeof(int));            // single variable on heap

    int *b = (int *)malloc(10 * sizeof(int));      // malloc(size in Bytes)
    // b is a heap allocated array of size 10
    // for(int i = 0; i < 10; i++) {
    //     cout << b[i] << ' ';
    // }
    // cout << '\n';

    ABC *r = (ABC*)malloc(sizeof(ABC));         // r is an object of class ABC on heap
    free(r);





    return 0;
}