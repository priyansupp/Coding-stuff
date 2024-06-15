#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)
const int MOD = (int)1e9 + 7;
void solve() {
    int n;
    cin >> n;
    char map[n + 1][n + 1];
    forr(i, 1, n + 1) forr(j, 1, n + 1) cin >> map[i][j];
    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = (map[1][1] == '.');
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) continue;
            if(map[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n][n];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}