#include<bits/stdc++.h>
using namespace std;


int MOD = 1e9 + 7;
int countways(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(i == 0){     // as arr[i] can be 0, so let the index go till the end.
        if(arr[i] == 0 && sum == 0) return 2;
        if(sum == 0) return 1;
        if(sum == arr[i]) return 1;
        return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    int notpick = countways(i - 1, sum, arr, dp);
    int pick = 0;
    if(sum >= arr[i]) pick = countways(i - 1, sum - arr[i], arr, dp);
    
    return dp[i][sum] = (pick + notpick) % MOD;
}


int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0;
    for(auto &i : arr) total += i;

    // s1 - s2 = d => total - 2*s2 = d => s2 = (total - d) / 2 and also s2 < s1 => s2 < total - s2 => s2 < total / 2. If first condition holds then second will automatically hold(for positive d).

    // as all elements >= 0 and integer, therefore s2 >= 0 and s2 must be integer
    if(total - d < 0 || (total - d) % 2) return 0;

    int k = (total - d)/2;
    // vector<vector<int>>dp(n, vector<int>(k + 1, -1));
    // return countways(n - 1, k, arr, dp);

    // TABULATION METHOD

    vector<vector<int>>dp(n, vector<int>(k + 1, 0));
    // dp[i][j] is number of sets we can get considering elements from 0 to i with sum = j.
    // conditions when i = 0, i.e dp[0][something] is base case
    if(arr[0] == 0) dp[0][0] = 2;   // both pick and notpick will give a subset
    else dp[0][0] = 1;              // when arr[0] != 0, there's only one way to get sum 0, by not picking arr[0] 

    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;   // If sum == arr[0], there's only one way, by picking arr[0]. The second cndtn is to stop out of bound error.

    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <=k; sum++){
            int notpick = dp[i - 1][sum];
            int pick = 0;
            if(sum >= arr[i]) pick = dp[i - 1][sum - arr[i]];
            
            dp[i][sum] = (pick + notpick) % MOD;
        }
    }
    return dp[n - 1][k];
}




int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, diff;
        cin >> n >> diff;
        vector<int>a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << countPartitions(n, diff, a) << '\n';
    }
    return 0;
}