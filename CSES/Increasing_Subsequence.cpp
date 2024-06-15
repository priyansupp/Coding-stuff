#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    int x[n + 1];
    forr(i, 1, n + 1) cin >> x[i];
    vector<int>dp(n + 1, 1);
    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            if(x[j] < x[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}