#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)
const int MOD = (int)1e9 + 7;
void solve() {
    int n;
    cin >> n;
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}