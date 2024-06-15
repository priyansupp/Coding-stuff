#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)
const int MOD = 1e9 + 7;

void get_all_masks(vector<int>&ans, int j, int mask, int n, int m) {
    if(j == n) {
        return;
    }

    if(mask >> j) {
        
    } 
}


ll dp[1001][(1 << 10)];
// dp[i][mask] : number of ways to cover tiles from i to m with mask at ith
// mask = (10110), then 1 represents there's already a perturbation of block and 0 represents no perturbation of block at ith column
ll solve(int i, int mask, int n, int m) {
    if(i == m) {
        return (mask == 0);
    }

    if(dp[i][mask] != -1) return dp[i][mask];

    ll ans = 0;
    vector<int>all_masks;
    get_all_masks(all_masks, 0, mask, n, m);
    for(int new_mask : all_masks) {
        ans += solve(i + 1, new_mask, n, m);
    }

    return dp[i][mask] = ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, n, m);
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}