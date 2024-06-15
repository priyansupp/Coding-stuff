// https://youtu.be/gNgUMA_Ur0U?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include<bits/stdc++.h>
using namespace std;

void fill2D(int** b, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] = i + j + 1;
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() 
{
    // 1D array with 20 blocks of memory
    int* a = new int[20];
    // a[i] is equivalent to *(a + i)
    // deleting
    delete[] a;

    // 2D array with 20*30 = 600 blocks of memory. Each of 30 blocks is at different MA
    // think of 2D arrray as b[i] is a pointer to each row.
    int** b = new int*[20];             // declare an array of size 20 to store 20 pointers. that's why new int*[20], int* indicates that each element b[i] would store an int*
    for(int i = 0; i < 20; i++) {       // then each pointer stores the MA address of start of 30 blocks of memory
        b[i] = new int[30];
    }
    // now our 2D array is ready, with 20 rows and 30 columns
    // int b[20][30];       // stack array equivalent
    b[2][4] = -5;           // assignment4

    fill2D(b, 20, 30);
    cout << b[0][0] << '\n';        // the array has change, as the function made changes to the array pointer(i.e directly to the MA of b)

    // deleting
    for(int i = 0; i < 20; i++) {
        delete[] b[i];              // delete each 30-block of memory for all 20 pointers(rows)
    }
    delete[] b;                     // then delete the 20-block of memory that was stored in b-array

    // 3D array
    int*** c = new int**[20];
    for(int i = 0; i < 20; i++) {
        int** d = new int*[30];
        for(int j = 0; j < 30; j++) {
            d[i] = new int[40];
        }
        c[i] = d;
    }
    // now our 3D array is ready, with size 20x30x40
    // int c[20][30][40];      // stack array equivalent
    // c[2][3][10] = 10;       // assignment
}