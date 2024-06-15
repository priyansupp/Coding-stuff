#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int v1, v2;
    cin >> v1 >> v2;
    int t, d;
    cin >> t >> d;

    ll dp[t + 1][1000];
    const ll inf = 1e17;

    // dp[i][j] denotes the maximum distance covered till time i with the speed of covering the distance being j.
    for(int i = 0; i <= t; i++) {
        for(int j = 0; j <= 1000; j++) {
            dp[i][j] = -inf;
        }
    }
    
    dp[1][v1] = v1;

    for(int i = 2; i <= t; i++) {
        for(int j = 1; j <= 1000; j++) {
            for(int k = -d; k <= d; k++){
                if(j + k > 0 && j + k < 1000)
                dp[i][j + k] = max(dp[i][j + k], dp[i - 1][j] + j);
            }
        }
    }

    cout << dp[t][v2];

    return 0;
}