#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, s;
    cin >> n >> s;
    vector<long long>a(n);
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    int l = 0, r = 0, minleng = INT_MAX;
    long long sum = 0;
    for(r = 0 ; r < n ; r++){    // sum >= s
        sum += a[r];
        while(sum - a[l] >=  s){   // subtracting the left pointer until the subtraction doesn't violates the invariant
            sum -= a[l];           // we've to find the shortest segment, therefore moving the left pointer until the condition is violated, that will yield te shortest ssegment.
            l++;
        }
        if(sum >= s) minleng = min(minleng, r - l + 1);   // finding the minimum of all the segments(only when the condition is saitisfied, it won't be satisfied in the start whem the sum will actually be less than s, so not considering those segments.)
    }
    if(minleng != INT_MAX) cout << minleng << '\n';
    else cout << -1 << '\n';
    return 0;
}