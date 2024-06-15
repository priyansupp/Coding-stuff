#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p , p + n);   
    int mid = n/2;       // median gives the minimum of sum of absolute differences of all elements to a fixed number.

    // suppose a1, a2, a3, a4, ... , an be in ascending order, so that fixed number must be in between a1, an (outside it will only increase the distance). Any number between a1, an would result in same distance sum from both these points. Now, any point between a2, a(n-1) would also give same distance sum for a2, a(n-1). Hence the fixed point must be between a1, an and between a2, a(n-1) and between a3, a(n-2) and .... to minimize the distance sums over all pairs of points.. this would eventually result in eiher 1 element in the end(which can be taken as the fixed point) or 2 elements out of which anything in between them(including them) would give the correct fixed point.
    // So, median is that required fixed point.

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(p[i] - p[mid]);
    }
    cout << ans ;
    
    return 0;

}