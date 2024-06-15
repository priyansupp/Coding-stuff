#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// FINDING ALL POSSIBLE SUMS FROM TABULATIN METHOD OF SUBSETSUM.CPP
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalsum = 0;
	for(int i = 0; i < n; i++) totalsum += arr[i];
    // using all the array elements(picking some and notpicking some), we find all the sums(s1) we can make. then s2 = s - s1 and then we can minimize s1 - s2 using the acquired sums.
    vector<vector<bool>>dp(n, vector<bool>(totalsum + 1, false));
    

    for(int i = 0; i < n ; i++){  // using if(sum == 0){ return true; } from memoization part
        dp[i][0] = true;
    }

    if(arr[0] <= totalsum) dp[0][arr[0]] = true; // using second base case from memoization part.

    for(int i = 1; i < n; i++){    // memoization went n - 1 to 0, therefore just reverse here
        for(int sum = 1; sum <= totalsum; sum++){  // memoization went sum = k to 0, therefore just reverse here(sum = 0 has been dealt as a base case already).
            bool pick = false;
            if(sum - arr[i] >= 0) pick = dp[i - 1][sum - arr[i]];
            bool notpick = dp[i - 1][sum];
            dp[i][sum] = (pick || notpick);
        }
    }
    int mini = 1e9;
    for(int sum = 0; sum <= totalsum; sum++){
        if(dp[n - 1][sum]){
            int s1 = sum;
            int s2 = totalsum - sum;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}


int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << minSubsetSumDifference(arr, n);

    return 0;
}