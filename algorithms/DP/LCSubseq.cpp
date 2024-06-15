#include<bits/stdc++.h>
using namespace std;

// s1 = "abcdefgh"
// s2 = "bcterg"
// LCS(i, j) represents longest common sub considering 0 to i of s1 and 0 to j of s2.
// In recursion, we start by last and build three cases: 
// 1. LCS(i - 1, j)    ans of (i, j) is same as (i - 1, j)
// 2. LCS(i, j - 1)    ans of (i, j) is same as (i, j - 1)
// 3. LCS(i - 1, j - 1)    ans of (i, j) is same as (i - 1, j - 1) if(s1[i] != s2[j]) and same as 1 + (i - 1, j - 1) when (s1[i] == s2[j]), i.e the last letters match
// Take maximum of all the cases.


// In tabulation, build from 0 index for both
// dp[i][j] represents longest common sub considering 0 to i of s1 and 0 to j of s2.
// In this also, build 4 cases.



class Solution {
public:
    int LCS(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        ans = max(ans, LCS(s1, s2, i - 1, j, dp));
        ans = max(ans, LCS(s1, s2, i, j - 1, dp));
        ans = max(ans, LCS(s1, s2, i - 1, j - 1, dp) + (s1[i] == s2[j]));

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return LCS(s1, s2, n1 - 1, n2 - 1, dp);
    }
    int longestCommonSubsequenceTabulation(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        dp[0][0] = (s1[0] == s2[0]);
        for(int i = 1; i < n1; i++){
            dp[i][0] = max((s1[i] == s2[0]) ? 1 : 0, dp[i - 1][0]);
        }
        for(int j = 1; j < n2; j++){
            dp[0][j] = max((s1[0] == s2[j]) ? 1 : 0, dp[0][j - 1]);
        }
        for(int i = 1; i < n1; i++){
            for(int j = 1; j < n2; j++){
                int ans = 0;
                ans = max(ans, dp[i - 1][j]);
                ans = max(ans, dp[i][j - 1]);
                ans = max(ans, dp[i - 1][j - 1] + (s1[i] == s2[j]));
                dp[i][j] = ans;
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution ANS;
    cout << ANS.longestCommonSubsequence(s1, s2) << '\n' << ANS.longestCommonSubsequenceTabulation(s1, s2);
    return 0;
}