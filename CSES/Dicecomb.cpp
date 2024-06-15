#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const MOD = 1e9+7;
int n;

// ways(sum) returns number of ways to get sum
// ways(sum) = ways(sum - 1) + ways(sum - 2) + ways(sum - 3) + ways(sum - 3) + ways(sum - 5) + ways(sum - 6) 
// because if can number of ways to get (sum - 1) then we just need to add 1 to get (sum), similarly with (sum - 2) add 2, with (sum - 3) add 3.
// Note: We can't add 1 and then 2 in (sum - 3) to get (sum) as adding 1 will give (sum - 2) which we've already counted in ways to get (sum - 2).


ll ways(int sum, int dp[])
{
    if(sum == 0) return 1;      // only one way to recieve a sum of 0, i.e select none.
    // if(sum < 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    ll s = 0;
    for(int i = 1; i <= 6; i++){
        if(sum - i >= 0) s += ways(sum - i, dp);    // if sum - i == 0, it means ways(0) which is equal to 1 way, hence to reach the 's' we'll just need to add i to 0(that is the only 1 way), that's why if sum == 0, return 0;
    }
    return dp[sum] = s%MOD;
}


int main()
{
    cin >> n;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));

    // MEMOIZATION METHOD
    // dp[0] = 1;
    // cout << ways(n, dp);


    // TABULATION METHOD
    dp[0] = 1;
    for(int j = 1; j <= n; j++){
        ll s = 0;
        for(int i = 1; i <= 6; i++){
            if(j-i >= 0) s += dp[j - i];    // builds as dp[0], dp[1], dp[2], ..... dp[n]
        }
        dp[j] = s%MOD;
    }
    cout << dp[n];
    
    return 0;
}