#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, (int)1e9));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int x = dp[i][j - 1], y = dp[i - 1][j], z = dp[i - 1][j - 1];
                dp[i][j] = min(dp[i][j], 1 + min(x, min(y, z)));
            }
        }
    }
    cout << dp[n][m];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}