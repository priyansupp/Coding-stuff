#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)
#define inf 1e18

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    ll dp[501][501];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = inf;
        }
    }
    forr(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[u][v], (ll)w);     // apparently edges can repeat, so take the minimum
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << (dp[u][v] == inf ? -1 : dp[u][v]) << '\n';
    }
    return 0;
}