#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

const int mod = 1e9 + 7;

int binary_exponentiation(int a, int b) {
    if(b == 0) return 1;
    ll res = binary_exponentiation(a, b / 2);
    res = (res * res) % mod;
    if(b % 2) res = (res * a) % mod;
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int res = binary_exponentiation(a, b);
    cout << res << '\n';
}


int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}