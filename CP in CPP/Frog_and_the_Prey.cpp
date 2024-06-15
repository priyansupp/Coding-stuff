#include <bits/stdc++.h>
using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;

int jumps(vector<int> &a, int n){
    vector<int>dp(n, 0);
    dp[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        int total = 1e8;
        for(int j = 1; j <= a[i] && j + i < n; j++){
            total = min(total, 1 + dp[i + j]);
        }
        dp[i] = total;
    }
    return dp[0];
}


// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[0] == 0){
        if(n == 1) cout << 0;
        else cout << -1;
        return;
    }
    int x = jumps(a, n);
    reverse(a.begin(), a.end());
    int y = jumps(a, n);
    if(x >= 1e8 || y >= 1e8) cout << -1;
    else cout << x + y;
    return;
}




int main()
{
    ll __ = 1;
    // cin >> __;
    while(__--){
        solve();
    }
    return 0;
}
