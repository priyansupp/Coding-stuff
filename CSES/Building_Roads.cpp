#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

struct DSU{
    vector<int>par, Size;
    DSU(int _par, int _Size) {
        par.resize(_par);
        Size.resize(_Size);
    }
    void make(int u) {
        par[u] = u;
        Size[u] = 1;
    }
    int find(int p) {
        if(p == par[p]) return p;
        return par[p] = find(par[p]);
    }
    void union_set(int u, int v) {
        u = find(u), v = find(v);
        if(u != v) {
            if(Size[u] < Size[v]) swap(u, v);
            par[v] = u;
            Size[u] += Size[v];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    struct DSU dsu = DSU(n + 1, n + 1);
    forr(i, 1, n + 1) dsu.make(i);
    int u, v;
    forr(i, 0, m){
        cin >> u >> v;
        dsu.union_set(u, v);
    }
    vector<pair<int, int>>ans;
    forr(i, 1, n + 1) {
        if(dsu.find(1) != dsu.find(i)) {
            ans.push_back({dsu.find(1), dsu.find(i)});
            dsu.union_set(dsu.find(1), dsu.find(i));
        }
    }
    cout << ans.size() << '\n';
    for(auto v : ans) cout << v.first << " " << v.second << '\n';
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}