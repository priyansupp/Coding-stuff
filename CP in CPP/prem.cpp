#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool exploreAll(vector<int> &c, int d, int i, vector<char>&s) {
    if(i < 0) return false;
    if(d == 0) {
        return true;
    }

    // take
    s[i] = '1';
    if(exploreAll(c, d - c[i], i - 1, s)) return true;
    
    // not take
    s[i] = '0';
    if(exploreAll(c, d, i - 1, s)) {
        return true;
    }

    return false;

}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>pair(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> pair[i].first >> pair[i].second;
        sum += pair[i].first;
    }

    int d = m - sum;        // we need this extra bit

    vector<int> c(n);
    vector<char>s(n);
    for(int i = 0; i < n; i++) {
        c[i] = pair[i].second - pair[i].first;
        s[i] = '0';
    }

    if(exploreAll(c, d, n - 1, s)){
        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << s[i];
        cout << '\n';
    } else cout << "NO\n";

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}