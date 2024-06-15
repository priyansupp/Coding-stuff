#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

const int MOD = (int)1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    int c[n];
    forr(i, 0, n) cin >> c[i];
    vector<ll>dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - c[j] >= 0) dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
        }
    }
    cout << dp[x];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}