#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)
const int MOD = (int)1e9 + 7;
void solve() {
    ll n;
    cin >> n;
    if((n * (n + 1)) % 4) {
        cout << 0;
        return;
    }
    ll target = n * (n + 1) / 4;
    // the problem is just like coin combination 2, except we can't use the coins more than once
    ll dp[n + 1][target + 1];                 // dp[i][j] = number of ordered ways to get a sum of j using numbers from 1 to i(each atmost 1 times)
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            int k = 0;
            if(j - i >= 0) k = dp[i - 1][j - i];
            dp[i][j] = (dp[i - 1][j] + k) % MOD;
        }
    }

    cout << dp[n - 1][target];              // number of ways to get a sum of target, using numbers 1...n-1, we don't use n so as to place it in the other set with other numbers, else in some cases that other set may be empty.
    // if a1,a2,a3,..,ak be numbers from 1...n-1 and their sum is target, then we know, 1+2+...+n = 2*target, hence sum of remaining numbers from set 1...n-1 and n would make up target(and resulting two partitions of 1...n would be non empty).
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}