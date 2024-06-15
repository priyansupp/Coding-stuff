#include<bits/stdc++.h>
using namespace std;

int fibrec(int n){
    if(n <= 1) return n;
    return fibrec(n - 1) + fibrec(n - 2);
}


int fibdp(int n, vector<int>&dp){    // we can avoid passing the vector parameter by declaring dp as global variable vector.
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];      // looking if dp already contains the value of the subproblem.

    return dp[n] = fibdp(n - 1, dp) + fibdp(n - 2, dp);   //memoization and returning of calls.
    // IT ESSENTIALLY MEANS
    // dp[n] = fibdp(n - 1, dp) + fibdp(n - 2, dp);
    // return dp[n];   
}



int main()
{

    int n;
    cin >> n;

    cout  << fibrec(n) << '\n';

    vector<int>dp(n + 1, -1);    // assumming fib sequence is 0,1,1,2,3,5,8,13,.....
    // All are -1

    cout << fibdp(n, dp) << '\n';


    // Iterative approach(tabulation method)
    dp[0] = 0;    // we know these two values
    dp[1] = 1;
    // dp[n] contains the nth fib number i.e fib(n).
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << '\n';

    // even better(reducing space complexity even further as we don't need dp[i-3] and less once done)
    int prev2 = 0;
    int prev = 1;
    for(int i = 2; i <= n; i++){
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    cout << prev << '\n';

    return 0;
}