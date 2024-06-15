#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

// weight is the weight of the knapsack.

int bookshop(int i, int weight, vector<int> &v, vector<int> &w, vector<vector<int>>&dp){
    if(i == 0){
        if(weight >= w[0]) return v[0];
        return 0;
    }
    if(dp[i][weight] != -1) return dp[i][weight];

    int pick = 0;
    if(weight - w[i] >= 0) pick = v[i] + bookshop(i - 1, weight - w[i], v, w, dp);
    int notpick = 0 + bookshop(i - 1, weight, v, w, dp);

    return dp[i][weight] = max(pick, notpick);
}

int main()
{
    int n, x;
    vector<int>h, s;
    cin >> n >> x;
    h.resize(n); s.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    // vector<vector<int>>dp(n, vector<int>(x + 1, -1));
    // cout << bookshop(n - 1, x, s, h, dp);

    vector<vector<int>>dp(n, vector<int>(x + 1, 0));
    for(int weight = 0; weight <= x; weight++){
        if(weight >= h[0]) dp[0][weight] = s[0];
    }
    for(int i = 1; i < n; i++){
        for(int weight = 0; weight <= x; weight++){
            int pick = -1e9;
            if(weight - h[i] >= 0) pick = s[i] + dp[i - 1][weight - h[i]];
            int notpick = 0 + dp[i - 1][weight];

            dp[i][weight] = max(pick, notpick);
        }
        
    }
    cout << dp[n - 1][x];
    return 0;
}