#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

// https://www.youtube.com/playlist?list=PLb3g_Z8nEv1hB69JL9K7KfEyK8iQNj9nX

ll dp[20][11][2][2];        // dp[n][last][leading][tight] : number of n digit numbers with last digit placed as last with leading and tight condition
// leading = 1 : we can still place leading zeros
// leading = 0 : we cannot place leading zeros
ll solve(string &R, int n, int last, bool leading, bool tight) {
    if(n == 0) return 1;

    if(dp[n][last][leading][tight] != -1) return dp[n][last][leading][tight];

    int ub = tight ? (R[R.length() - n] - '0') : 9;
    ll ans = 0;
    for(int dig = 0; dig <= ub; dig++) {
        if(dig == last && leading == 0) continue;       // if digits match (after leading zero has been stopped)
        ans += solve(R, n - 1, dig, leading & (dig == 0), tight & (dig == ub));     // leading && dig == 0 then only leading will remain 1
    }

    return dp[n][last][leading][tight] = ans;
}


void solve() {
    ll a, b;
    cin >> a >> b;
    a--;
    string l = to_string(a), r = to_string(b);
    memset(dp, -1, sizeof dp);
    ll x1 = solve(r, r.length(), 10, 1, 1);
    memset(dp, -1, sizeof dp);
    ll x2 = (a == -1 ? 0 : solve(l, l.length(), 10, 1, 1));
    cout << x1 - x2;
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}