#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




// NOT A GOOD METHOD

// bool subsetsum(int i, int sum, vector<int> &arr, vector<vector<int>>& dp){
//     if(i < 0){
//         return false;
//     }
    
//     if(sum < 0){
//         return false;
//     }
    
//     if(sum == 0){
//         return true;
//     }
//     if(dp[i][sum] != -1){
//         if(dp[i][sum] == 1) return true;
//         else return false;
//     }
    
//     bool pick = subsetsum(i - 1, sum - arr[i], arr, dp);
//    	bool notpick = subsetsum(i - 1, sum, arr, dp);
    
//     return dp[i][sum] = (pick || notpick);
// }


// bool subsetSumToK(int n, int k, vector<int> &arr) {
// //     vector<vector<int>>dp(n, vector<int>(k + 1, -1));
// //     return subsetsum(n - 1, k, arr, dp);
//     vector<vector<bool>>dp(n, vector<bool>(k + 1, false));
//     for(int i = 0; i < n; i++){
//         dp[i][0] = true;
//     }
    
//     for(int i = 0; i < n; i++){
//         for(int sum = 1; sum <= k; sum++){
//             if(i == 0){				// whole of this if condtion means that only dp[0][arr[0]] is true rest all are false.
//                 if(sum == arr[i]) dp[i][sum] = true;
//                 else dp[i][sum] = false;
//             }
//             else{
//                 bool pick= false;
//                 if(sum - arr[i] >= 0) pick = dp[i - 1][sum - arr[i]];
//                 bool notpick = dp[i - 1][sum];
//                 dp[i][sum] = pick || notpick;
//             }
//         }
//     }
    
//     return dp[n - 1][k];
    
// }




// GOOD METHOD


// subsetsum(i, sum, arr, dp) signifies if we can add elements to get 'sum' using elements upto ith index. (If it's true for j < i then it's true for all i's >= j).
bool subsetsum(int i, int sum, vector<int>& arr, vector<vector<int>>& dp){ 

    // don't ever let negative indices arise in recursion as they get harder to deal with(hell lots of if statements). Always try to stop at the base case.
    // METHOD 1 TO WRITE BASE CASE. STOP & RETURN AS SOON AS SUM == 0
    // if(sum == 0){
    //     return true;
    // }
    // if(i == 0){
        // if(arr[i] == sum) return true;
        // else return false;
    // }

    // METHOD 2 OF WRITING BASE CASE. LET IT GO TILL THE END. IF SUM == 0 BEFORE BASE CASE IS HIT THEN ALSO IT'LL KEEP GOING TILL THE END IN NOT-PICK CONDITION (useful in counting number of subsets summing upto k and has 0 elements also, let it go till index 0, as even if sum == 0 before i = 0, there can be indcies storing 0(or negative numbers) that may create another subset).
    if(i == 0){     
        if(sum == 0 || sum == arr[i]) return true;
        else return false;
    }
    if(dp[i][sum] != -1){
        if(dp[i][sum] == 1)  return true;
        else return false;
    }
    
    bool pick = false;
    if(sum - arr[i] >= 0) pick = subsetsum(i - 1, sum - arr[i], arr, dp);

    bool notpick = subsetsum(i - 1, sum, arr, dp);
    
    return dp[i][sum] = (pick || notpick);
}


bool subsetsumTok(int n, int k, vector<int> &arr)
{
    vector<vector<int>>dp(n, vector<int>(k + 1, -1));   // integer vector for memoization
    return subsetsum(n - 1, k, arr, dp);

    // bool vector for tabulation
    // vector<vector<bool>>dp(n, vector<bool>(k + 1, false));
    

    // for(int i = 0; i < n ; i++){
    //     dp[i][0] = true;
    // }

    // if(arr[0] <= k) dp[0][arr[0]] = true;

    // for(int i = 1; i < n; i++){    // memoization went n - 1 to 0, therefore just reverse here
    //     for(int sum = 1; sum <= k; sum++){  // memoization went sum = k to 0, therefore just reverse here(sum = 0 has been dealt as a base case already).
    //         bool pick = false;
    //         if(sum - arr[i] >= 0) pick = dp[i - 1][sum - arr[i]];
    //         bool notpick = dp[i - 1][sum];
    //         dp[i][sum] = (pick || notpick);
    //     }
    // }
    
    // return dp[n - 1][k];
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(subsetsumTok(n, k, a)) cout << "true";
    else cout << "false";

    return 0;
}