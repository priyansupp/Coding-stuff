#include<bits/stdc++.h>
using namespace std;

long long w,h,n;


//good() function is for checking whether for a given x(size of the square), will it be able to fit n a*b rectangles
bool good(long long x){        
    return (x/w)*(x/h) >= n;
}


int main()
{
    cin>>w>>h>>n;

    long long l = 0;   //definitely a bad number(no rectangle can be inscribed in 0*0 square)
    long long r = 1;
    while(!good(r)) r *= 2;     //now r will be good that is maximum twice away from minimum good size

    // INVARIANCE OF THIS BINARY SEARCH
    // if r-good then r+1 is good
    // if l is bad then l-1 is bad
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 ..... It is like doing binary search in list of numbers for a minimum number with the above good() function(condition) keeping in mind.

    while(r > l+1){
        long long m = (l+r)/2;
        if(good(m)){
            r = m;
        }
        else{
            l = m;
        }
    }

    cout<<r<<'\n';

} 