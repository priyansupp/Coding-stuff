#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<ll>a(n), b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < k; i++) cin >> b[i];
    sort(b.begin(), b.end());

    // the idea is that there shouldnt be any crossing. i.e, 
    // 20 40 55 80 120          // people
    // 10 30 40 60 90 105 130   // keys
    // office = 70
    // then if 20 takes key at 30, then 40 cant take the key at 10, because it'd just increase the net total by criss-cross
    // therefore people would take keys in increasing order.
    // dp[i, j] denotes minimum time to reach office for i keys been taken by first 'j' people.
    // ans = dp[k][n]       k keys and n people minimum time
    ll dp[k + 1][n + 1];
    const ll inf = 1e17;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = inf;
        }
        dp[i][0] = 0;       // with 0 people and any number of keys, minimum time will be 0.
    }

    for(int i = 1; i <= k; i++) {        // for keys
        for(int j = 1; j <= n; j++) {    // for person
            int k_ind = i - 1, p_ind = j - 1;
            dp[i][j] = min(dp[i - 1][j], max(abs(a[p_ind] - b[k_ind]) + abs(p - b[i - 1]), dp[i - 1][j - 1]));
        }
    }

    cout << dp[k][n];


    return 0;
}