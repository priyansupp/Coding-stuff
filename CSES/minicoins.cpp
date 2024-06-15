#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// ll f(int sum, vector<int> &dp, int n, vector<int> &c){
//     if(sum == 0) return 0;
//     if(sum < 0) return -10;
//     if(dp[sum] != -1) return dp[sum];
    
//     ll miniways = INT_MAX;
//     for(int i = 0; i < n; i++){
//         ll t = 1 + f(sum - c[i], dp, n, c);
//         if(t > 0) {
//             miniways = min(miniways, t);
//         }
//     }
//     if(miniways == INT_MAX) return dp[sum] = -10;
//     else return dp[sum] = miniways;
// }

// BEST PICK/NOTPICK SOLUTION(BEST WAY TO SOLVE THIS QUESTION)
int countminiways(int i, int target, vector<int> &num, vector<vector<int>> &dp){

    if(i == 0){         // at 0th index if num[0] = 3 and target = 9 then picking 3 such coins is the only choice. If num[0] = 5 and target = 16, there is no way target can be acheived, hence return INT_MAX.
        if(target % num[0] == 0) return target / num[0];
        return 1e9;
    }
    
    if(dp[i][target] != -1) return dp[i][target];
    
    int notpick = 0 + countminiways(i - 1, target, num, dp);
    int pick = 1e9;
    if(num[i] <= target) pick = 1 + countminiways(i, target - num[i], num, dp);     // infinite supply of coins, therefore we can pick the same coin again(don't decrease i).
    
    return dp[i][target] = min(pick, notpick);
}


int minimumElements(vector<int> &num, int target)
{
    int n = num.size();
    // vector<vector<int>>dp(n, vector<int>(target + 1, -1));
    // int ans = countminiways(n - 1, target, num, dp);
    
    // TABULATION METHOD
    vector<vector<int>>dp(n, vector<int>(target + 1, 0));
    for(int t = 0; t <= target; t++){
    	if(t % num[0] == 0) dp[0][t] = t / num[0];
        else dp[0][t] = 1e9;
    }
    
    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <= target; sum++){
            int notpick = 0 + dp[i - 1][sum];
            int pick = 1e9;
            if(num[i] <= sum) pick = 1 + dp[i][sum - num[i]];

            dp[i][sum] = min(pick, notpick);
        }
    }
    int ans = dp[n - 1][target];
    if(ans >= 1e9) return -1;    
    return ans;
    
}



int main()
{
    int n,x;
    vector<int>c;
    cin >> n >> x;
    c.resize(n);
    vector<int>dp(1000001, -1);
    for(int i = 0; i < n; i++) cin >> c[i];

    // if(f(x, dp, n, c) < 0) cout << -1;
    // else cout << f(x, dp, n, c);

    cout << minimumElements(c, x);


    return 0;
}