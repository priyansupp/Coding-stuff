#include<bits/stdc++.h>
using namespace std;

// coding ninjas question
int maxpoints(int i, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(i == 0){
        int maxi = 0;
        for(int j = 0; j < 3; j++){
            if(last != j){
                int x = points[i][j];
                maxi = max(maxi, x);
            }
        }
        return maxi;
    }
    if(dp[i][last] != -1) return dp[i][last];
    
    int maximum = 0;
    for(int j = 0; j < 3; j++){
        if(last != j){
            int x = points[i][j] + maxpoints(i - 1, j, points, dp);
            maximum = max(maximum, x);
        }
    }
    
    return dp[i][last] = maximum;
    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // vector<vector<int>>dp(n, vector<int>(4, -1));
    // return maxpoints(n - 1, 3, points, dp);

    // dp[i][j] means the maximum points earned by the ninja till level i when the task done at next day(i + 1) is task j. (when j == 3 it means there is no next day/task).

    int dp[n][4] = {0};
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int i = 1; i < n; i++){
        for(int last = 0; last < 4; last++){
            int maximum = 0;
            for(int j = 0; j < 3; j++){
                if(last != j){
                    int x = points[i][j] + dp[i - 1][j];
                    maximum = max(maximum, x);
                }
            }
            dp[i][last] = maximum;
        }
    }
    int ans = -1e9;
    for(int last = 0; last < 4; last++){
        ans = max(ans, dp[n - 1][last]);
    }
    return ans;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; 
        vector<vector<int>>points(n, vector<int>(3));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++) cin >> points[i][j];
        }
        cout << ninjaTraining(n, points) << '\n';
    }
    
    
    return 0;
}