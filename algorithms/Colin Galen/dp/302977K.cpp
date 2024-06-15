#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    ll dp[k + 1][n + 1];        // k is length of sequence and n is numbers till where we can use to build the sequence.
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    // dp[i][j] denotes the total number of sequences possible with length being i and numbers used till 1...j
    for(int i = 0; i < k; i++) {
        for(int j = 1; j <= n; j++) {
            for(int v = j; v <= n; v += j) {        // logn number of factors
                dp[i + 1][v] = (dp[i + 1][v] + dp[i][j]) % MOD;
            }
        } 
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + dp[k][i]) % MOD;
    cout << ans;
    return 0;
}


