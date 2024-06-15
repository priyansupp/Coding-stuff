#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, x;
    cin >> n >> x;
    int h[n + 1], s[n + 1];
    forr(i, 1, n + 1) cin >> h[i];
    forr(i, 1, n + 1) cin >> s[i];
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    for(int p = h[1]; p <= x; p++) {
        dp[1][p] = s[1];                    // can always purchase the first book if more money than required to get the first book
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            int k;
            if(j - h[i] >= 0) k = s[i] + dp[i - 1][j - h[i]];
            else k = 0;
            dp[i][j] = max(dp[i - 1][j], k);
        }
    }
    cout << dp[n][x];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}