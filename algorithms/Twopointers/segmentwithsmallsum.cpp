#include<bits/stdc++.h>
using namespace std;

//  a[l..r] (1≤l≤r≤n) is good if the sum of elements on this segment is at most s, i.e sum <= s.
// find the longest good segment.

int main()
{
    long long n, s;
    cin >> n >> s;
    vector<long long>a(n);
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    int l = 0, r = 0, maxleng = 0;
    long long sum = 0;
    for(r = 0 ; r < n ; r++){    // sum <= s
        sum += a[r];           // addition(inclusion)
        while(sum > s){    // moving the left pointer until sum becomes less than s. We can do this because a's are > 1(positive).
            sum -= a[l];   // subtraction(removal)
            l++;
        }
        maxleng = max(maxleng, r - l + 1);   // finding the maximum of all the segments
    }
    cout << maxleng << '\n';
    return 0;
}