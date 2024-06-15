#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

const int MOD = (int)1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    int c[n + 1];
    c[0] = 0;
    forr(i, 1, n + 1) cin >> c[i];
    sort(c, c + n + 1);             // as it is sorted, each would appear in the same order. Because we consider the coins in order, we will only count one order of coins.
    int dp[n + 1][x + 1];           // dp[i][x] = number of ways to make sum x using coins till index i
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;                   // ways to make sum 0 using 0 coins = 1, i.e pick no coins
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            int k;
            if(j - c[i] >= 0) k = dp[i][j - c[i]];
            else k = 0;
            dp[i][j] = (dp[i - 1][j] + k) % MOD;
        }
    }
    cout << dp[n][x];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}