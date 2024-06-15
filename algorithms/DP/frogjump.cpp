#include<bits/stdc++.h>
using namespace std;

int k;
vector<int>h;

// MEMOIZATION METHOD WITH 2 JUMPS. energy(n, dp) is the minimum energy required to go from level 1 to n.
int energy(int n, int dp[]){
    if(dp[n] != -1) return dp[n];
    if(n == 2) return abs(h[1] - h[0]);
    if(n == 1) return 0;
    
    int x1 = energy(n - 1, dp) + abs(h[n - 1] - h[n - 2]);
    int x2 = energy(n - 2, dp) + abs(h[n - 1] - h[n - 3]);

    return dp[n] = min(x1, x2);
}


// MEMOIZATION WITH K JUMPS
int energyk(int n, int dpk[]){
    if(dpk[n] != -1) return dpk[n];
    if(n == 1) return 0;
    int mini = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(n - i >= 1){
            int x = energyk(n - i, dpk) + abs(h[n - 1] - h[n - 1 - i]);
            mini = min(x, mini);
        }
    }
    return dpk[n] = mini;
}



int main()
{
    int n;
    cin >> n;
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    cout << energy(n, dp) << '\n';


    // TABULATION METHOD WITH 2 JUMPS
    memset(dp, -1, sizeof(dp));
    dp[2] = abs(h[1] - h[0]);
    dp[1] = 0;
    for(int i = 3; i <= n; i++){
        int x1 = dp[i - 1] + abs(h[i - 2] - h[i - 1]);     // jump of 1 step to reach at step i.. the jump must be from (i-1)th step to ith step... heights follow 0 based indexing that's why that extra -1 in both
        int x2 = dp[i - 2] + abs(h[i - 3] - h[i - 1]);   // can only jump to 3rd step or higher
        dp[i] = min(x1, x2);
    }
    cout << dp[n] << '\n';

    // K JUMPS
    int dpk[n + 1];
    memset(dpk, -1, sizeof(dpk));
    cin >> k;
    cout << energyk(n, dpk) <<  '\n';

    // TABULATION METHOD WITH K JUMPS
    memset(dpk, -1, sizeof(dpk));
    dpk[1] = 0;

    int x;
    for(int i = 2; i <= n; i++){
        int mini = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i - j >= 1){                  // a jump can't start from negative or zeroth position, it must start from a positive position(legit staircase).
                mini = min(mini, dpk[i - j] + abs(h[i - 1 - j] - h[i - 1]));
            } else break;
        }
        dp[i] = mini;
    }

    cout << dpk[n] << '\n';

    return 0;
}