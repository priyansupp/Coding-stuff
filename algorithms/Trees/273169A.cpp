#include <bits/stdc++.h>
using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;

const ll MOD = 1e9+7;
const ld PI = acos(-1.0);

#define forr(i, a, n)   for(ll i = a; i < n; i++)

const int N = 1e6;
ll a[N], seg[4 * N];

void buildseg(int ind, int low, int high){
    if(low == high){
        seg[ind] = a[low];  // (= a[high])
        return;
    }
    int mid = (low + high) / 2;
    buildseg(2 * ind + 1, low, mid);
    buildseg(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll query(int ind, int low, int high, int l, int r){
    if(l <= low && r >= high){
        return seg[ind];
    }
    if(low > r || high < l){
        return 0;
    }
    int mid = (low + high) / 2;
    ll left = query(2 * ind + 1, low, mid, l, r);
    ll right = query(2 * ind + 2, mid + 1, high, l, r);
    return left + right;
}

void setseg(int node, int v, int ind, int low, int high){
    if(low == high){
        seg[ind] = v;
        return;
    }
    int mid = (low + high) / 2;
    if(node <= mid && node >= low) setseg(node, v, 2 * ind + 1, low, mid);
    else setseg(node, v, 2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    int n, m;
    cin >> n >> m;
    forr(i, 0, n) cin >> a[i];
    buildseg(0, 0, n - 1);
    while(m--){
        int x;
        cin >> x;
        if(x == 1){
            int i, v;
            cin >> i >> v;
            setseg(i, v, 0, 0, n - 1);
        }else{
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r - 1) << '\n';
        }
    }
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
