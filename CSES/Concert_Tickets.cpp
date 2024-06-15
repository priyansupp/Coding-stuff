#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>h(n), t(m);
    forr(i, 0, n) cin >> h[i];
    forr(i, 0, m) cin >> t[i];
    sort(h.begin(), h.end());
    
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}