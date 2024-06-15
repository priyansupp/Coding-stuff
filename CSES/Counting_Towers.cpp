#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

const int MOD = (int)1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    int dp[n + 1];                           // dp[i] = number of towers of height i
    dp[1] = 1;
    dp[2] = 8;
    for(int i = 3; i <= n; i++) {
        dp[i] = 5 * dp[i - 1];
    }
    cout << dp[n] << '\n';
}


int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}