// https://www.geeksforgeeks.org/sum-of-xor-of-all-subarrays/
// https://codeforces.com/blog/entry/105589
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int ones[n], pref[n];
    for(int i = 0; i < 30; i++) {
        ones[0] = a[0] & (1 << i);
        for(int j = 1; j < n; j++) {
            ones[j] = ones[j - 1] + (a[j] & (1 << i));
        }
        // pref[j] : denotes number of indices(ind) to the right of index j(including j) with odd number of 1's from [0...ind]
        pref[n - 1] = (ones[n - 1] % 2);
        for(int j = n - 2; j >= 0; j--) {
            pref[j] = pref[j + 1] + (ones[j] % 2);
        }
        bool odd = true;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(j > 0 && (a[j - 1] & (1 << i))) odd = !odd;  // check this in example below, when j-1 is 1 then parity changes
            if(odd) {
                sum += pref[j];
            } else {
                sum += n - j - pref[j];                     // when parity changes, we want to find number of indices to the right of index j(including j) with even number of 1's 
            }
        }
        ans += sum * (1 << i);
    } 
    cout << ans;
    return 0;
}

// Let for ith bit the array is like this
// 0 1 0 0 0 1 1 0 1 0 1
// 0 1 1 1 1 2 3 3 4 4 5 -> ones -> ones[j] : denotes number of ones till that index
// 7 7 6 5 4 3 3 2 1 1 1 -> pref -> pref[j] : denotes number of indices to the right of index j(including j) with odd number of 1's 
