#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int>a(n), t(n);
    for(int i =0; i< n; i++) cin >> a[i];
    for(int i =0; i< n; i++) cin >> t[i];
    ll sum = 0;
    for(int i =0; i< n; i++) {
        sum += t[i] * a[i];
    }

    // int l = 0;
    ll extra = 0, ans = 0;

    // for(int r = 0; r < n; r++) {
    //     if(t[r] == 0) {
    //         extra += a[r];
    //     }

    //     if(r - l + 1 == k) {
    //         ans = max(ans, sum + extra);
    //         // cout << ans << '\n';
    //         extra -= (t[l] == 1) ? 0 : a[l];
    //         l++;
    //     }
    // }

    // dp approach using prefix sum

    vector<int>prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (1 - t[i - 1]) * a[i - 1];
    }

    for(int i = k; i <= n; i++) {
        ans = max(ans, sum + prefix[i] - prefix[i - k]);
    }

    cout << ans;


    return 0;
}