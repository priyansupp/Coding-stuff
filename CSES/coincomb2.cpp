#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;



// if we can take multiple coins of same denomination(elements can be duplicated but not the complete set i.e two sets with all same elements will count as 1 only i.e [2, 3, 2, 2] and [3, 2, 2, 2] are not different).
// DO SUCH QUESTIONS IN WHICH ORDER OF ELEMENTS IN FINAL ANSWER DOES NOT MATTER BY PICK/NOT-PICK METHOD.

// ll uniqcoincomb(int ind, int sum){
//     if(sum > x) return 0;
//     if(sum == x) return 1;
//     if(ind >= n) return 0;   // this condition will only occur when ind >= n and sum != x

//     sum += c[ind];           // adding
//     ll left = uniqcoincomb(ind, sum);   // after picking, we can pick it again(if not, we would have increased the ind by 1)

//     sum -= c[ind];           // removal
//     ll right = uniqcoincomb(ind + 1, sum); // if we didn't pick then we can simply move on

//     return left + right;

// }


ll uniqdp(int ind, int sum, vector<int> &c, vector<vector<ll>> &dp){
    if(ind == 0){
        if(sum == 0) return 1;      // if sum == 0, just don't pick that last coin and we've one order of coins
        if(sum % c[ind] == 0) return 1;     // at 0th index if c[0] = 3 and sum = 9 then picking 3 such coins is the only choice.
        return 0;       // If c[0] = 5 and sum = 16, there is no way sum can be acheived, hence return 0.
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];

    ll notpick = uniqdp(ind - 1, sum, c, dp) % MOD;      // if we didn't pick then we can simply move on
    ll pick = 0;
    if(c[ind] <= sum) pick = uniqdp(ind, sum - c[ind], c, dp) % MOD;  // after picking, we can pick it again(if not, we would have increased the ind by 1)

    return dp[ind][sum] = (pick + notpick) % MOD;
}



int main()
{
    
    int n, x;
    vector<int>c;
    cin >> n >> x;
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    // vector<vector<ll>>dp(n, vector<ll>(x + 1, -1));
    // cout << uniqdp(n - 1, x, c, dp) << '\n';


    vector<vector<ll>>dp(n, vector<ll>(x + 1, 0));
    vector<ll>prev(x + 1);
    for(int sum = 0; sum <= x; sum++){
        if(sum % c[0] == 0) prev[sum] = 1;
        else prev[sum] = 0;
    }
    for(int ind = 1; ind < n; ind++){
        vector<ll>curr(x + 1);
        for(int sum = 0; sum <= x; sum++){
            ll notpick = prev[sum] % MOD;
            ll pick = 0;
            if(c[ind] <= sum) pick = curr[sum - c[ind]] % MOD;
            curr[sum] = (pick + notpick) % MOD;
        }
        prev = curr;
    }
    cout << prev[x];

    // BOTH MEMOIZATION AND TABULATION ARE CORRECT SOLUTIONS, IDK WHY CSES IS NOT ACCEPTING(CODING NINJAS ACCEPTED).



    // IN BOTH FOLLOW-UP QUESTION, ORDER OF ELEMENTS IN FINAL ANSWER DOES NOT MATTER, SO DO BY PICK/NOT-PICK METHOD.

    // if we are given coin set in which we can use coin exactly once
    // c = [1, 2, 3] and sum = 3(it's just like finding all subsequences(gurantees no duplicates in case of ordering of elements) in which elements add upto 3.. i.e [1, 2] and [3]).

    // c = [1, 2, 1, 3, 1] and sum = 5 is more interesting case(we can't do by subsequence as the set of subsequences may contain two(or more) exact same subsequences formed using two different 1's).
    // Sorting.. [1, 1, 1, 2, 3] now it translates to a very tough problem. See this..  
    // https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=9&ab_channel=takeUforward

    return 0;
}




