#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

int up[(int)2e5 + 10][20];      // up[u][x] = 2^x levels up ancestor of u
int lvl[(int)2e5 + 10];
vector<int>adj[(int)2e5 + 10];
int n, q;

void binary_lifting(int u, int par) {
    up[u][0] = par;
    for(int i = 1; i < 20; i++) {
        if(up[u][i - 1] != -1)
            up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for(int v : adj[u]) {
        if(v != par) {
            lvl[v] = 1 + lvl[u];
            binary_lifting(v, u);
        }
    }
}

int find(int x, int k) {
    while(k) {
        int MSB = 31 - __builtin_clz(k);
        k ^= (1 << MSB);
        x = up[x][MSB];
        if(x == -1) return -1;
    }
    return x;
}

int lca(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    u = find(u, lvl[u] - lvl[v]);

    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(up, -1, sizeof up);
    // root = 1
    binary_lifting(1, -1);

    forr(i, 0, q) {
        int u, v;
        cin >> u >> v;
        int LCA = lca(u, v);
        int distance = lvl[u] + lvl[v] - 2 * lvl[LCA];
        cout << distance << '\n';
    }
    return 0;
}