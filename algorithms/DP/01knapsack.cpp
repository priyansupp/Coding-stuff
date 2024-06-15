#include<bits/stdc++.h>
using namespace std;

// maxivalue(i, wt) denotes the maximum sum we can obtain by considering indices upto i.

int maxivalue(int i, int wt, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
    if(i == 0){
        if(weight[0] <= wt) return value[0];    // if weight of item is less than the weight of knapsack, it'd be picked
        else return 0;                          // if weight of item is more than the weight of knapsack, it won't be picked and thus maxivalue(0, wt) should return 0.
    }

    if(dp[i][wt] != -1) return dp[i][wt];

    int notpick = 0 + maxivalue(i - 1, wt, weight, value, dp);
    int pick = -1e9;
    if(weight[i] <= wt) pick = value[i] + maxivalue(i - 1, wt - weight[i], weight, value, dp);
    
    return dp[i][wt] = max(pick, notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // vector<vector<int>>dp(n, vector<int>(maxWeight + 1, -1));
	// return maxivalue(n - 1, maxWeight, weight, value, dp);

    vector<vector<int>>dp(n, vector<int>(maxWeight + 1, 0));

    // dp[i][wt] denotes the maximum sum we can obtain by considering indices upto i with weight of knapsack being wt.
    for(int w = weight[0]; w <= maxWeight; w++) dp[0][w] = value[0];    // base case when i = 0

    for(int i = 1; i < n; i++){
        for(int wt = 0; wt <= maxWeight; wt++){
            int notpick = 0 + dp[i - 1][wt];
            int pick = -1e9;
            if(weight[i] <= wt) pick = value[i] + dp[i - 1][wt - weight[i]];
            
            dp[i][wt] = max(pick, notpick);
        }
    }
    return dp[n - 1][maxWeight];

}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>wi(n), vi(n);
        for(int i = 0; i < n; i++) cin >> wi[i];
        for(int i = 0; i < n; i++) cin >> vi[i];
        int W;
        cin >> W;
        cout << knapsack(wi, vi, n, W) << '\n';
    }
    return 0;
}