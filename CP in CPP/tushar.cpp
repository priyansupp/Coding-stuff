#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int N, M, K, X;
ll ans;
ll dp[1001];
ll bin(int x, int p) {
    if(p == 0) return 1;
    ll a = bin(x, p / 2);
    a *= a;
    if(p % 2) return a * x;
    return a;
}

ll solve(int row, int N, int prev) {
    if(row > N) return ans;

    for(int i= max(1, prev-X); i<=min(prev + X, X); i++){
        ans *= solve(row+1, N, i)*dp[i];
    }
    return ans;
}

int main() {
    ans = 1;
    cin >> N >> M >> K >> X;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= K; i++) {
        dp[i] = bin(i, M);
    }
    ans = solve(0, N, 0);
    cout << ans << '\n';    
    return 0;
}