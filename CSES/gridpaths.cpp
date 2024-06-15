#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int gridpath(int i, int j, vector<vector<char>> &v, vector<vector<int>>&dp){     // top-down aproach. We started from right lower box and counted the total ways up till 0,0
    if(i < 0 || j < 0) return 0;
    if(v[i][j] == '*') return 0;            // dead-cell, no way can be forged from there on
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int up = gridpath(i - 1, j, v, dp);
    int left = gridpath(i, j - 1, v, dp);

    return dp[i][j] = (up + left)%MOD;

}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>>v(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        cin >> v[i][j];
    }
    vector<vector<int>>dp(n, vector<int>(n, -1));
    // cout << gridpath(n - 1, n - 1, v, dp);

    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0) continue;
            int up = 0, left = 0;
            if(i >= 1) up = dp[i - 1][j];
            if(j >= 1) left = dp[i][j - 1];
            dp[i][j] = (up + left)%MOD;
        }
    }
    cout << dp[n - 1][n - 1];

    return 0;
}