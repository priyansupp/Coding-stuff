#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    int x[n + 1];
    forr(i, 1, n + 1) cin >> x[i];
    // dp[i][j] = true if it is possible to make j using coins 1...i, false otherwise
    bool dp[n + 1][1000 * n + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 1000*n; j++) {
            bool k = false;
            if(j - x[i] >= 0) k = dp[i - 1][j - x[i]];
            dp[i][j] |= dp[i - 1][j] || k;
        }
    }
    vector<int>ans;
    for(int j = 1; j <= 1000 * n; j++) {
        if(dp[n][j]) {
            ans.push_back(j);
        }
    }
    cout << ans.size() << '\n';
    for(int v : ans) cout << v << " ";
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}