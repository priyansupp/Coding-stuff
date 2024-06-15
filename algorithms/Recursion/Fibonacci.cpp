#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// 0,   1,   1,   2,   3,   5,   8,   13,  21,  34,  ....
// 0th, 1st, 2nd, 3rd, 4th, 5th, 6th, 7th, 8th, 9th, ....


ll fibo(int n){
    if(n <= 1) return n;

    ll last = fibo(n - 1);
    ll slast = fibo(n - 2);

    return last + slast;

    // or directly 
    // return fibo(n - 1) + fibo(n - 2);
}


int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}