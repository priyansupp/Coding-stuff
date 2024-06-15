#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, x;
    cin >> n >> x;
    int c[n];
    forr(i, 0, n) cin >> c[i];
    vector<ll>dp(x + 1, (int)INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - c[j] >= 0) dp[i] = min(dp[i], 1 + dp[i - c[j]]);
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}