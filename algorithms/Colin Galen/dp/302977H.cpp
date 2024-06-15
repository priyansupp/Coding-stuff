#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int>s(n), c(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    ll dp[n][4];

    for(int i = 0; i < n; i++) {
        for(int len = 0; len <= 3; len++) {
            dp[i][len] = INT_MAX;
        }
    }

    for(int i = 0; i < n; i++) {
        dp[i][1] = c[i];
    }

    for(int i = 1; i < n; i++) {
        for(int len = 2; len <= 3; len++) {
            for(int j = i - 1; j >= 0; j--) {
                if(s[j] < s[i]) dp[i][len] = min(dp[i][len], dp[j][len - 1] + c[i]);
            }
        }
    }

    ll ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[i][3]);
    }

    ans == INT_MAX ? cout << -1 : cout << ans;

    return 0;
}