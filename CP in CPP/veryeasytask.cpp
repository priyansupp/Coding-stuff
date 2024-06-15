#include<bits/stdc++.h>
using namespace std;

long long n,x,y;

bool good(long long t){    // return true if in given time t, n sufficient copies can be printed
    long long left = t - min(x,y);    //initially only one printer can make a copy
    if(left >= 0){
        return left/x + left/y + 1 >= n;    // checking if total copy is >= n
    }
    else{          // if left < 0, it means there is not even sufficient time to print a single copy.
        return false;
    }
}


int main()
{
    cin>>n>>x>>y;

    long long l = 0;   //definitely bad
    long long r = 1e10; //definitely good
    while(r > l + 1){
        long long m = (l+r)/2;
        if(good(m)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout<<r<<'\n';
    return 0;
}