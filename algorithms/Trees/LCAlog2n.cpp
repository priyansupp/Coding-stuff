#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

int up[(int)2e5 + 10][20];      // up[u][x] = 2^x levels up ancestor of u
int lvl[(int)2e5 + 10];
vector<int>adj[(int)2e5 + 10];
int n, q;

// binary_lifting(u, par) fills the array "up" with its ancestors 1,2,4,8,16.. level up the hierarchy 
// O(nlogn)
void binary_lifting(int u, int par) {
    up[u][0] = par;             // 2^0 levels up is parent itself
    for(int i = 0; i < 20; i++) {
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

// finds ancestor of x, k levels up the tree : O(logn)
int find(int x, int k) {
    if(k == 0) return x;            // 0 levels up is x itself
    // k = (1011) = 2^3 + 2^1 + 2^0 = find 2^3 levels up from current and from there find 2^1 levels up from there and from there find 2^0 levels up from there.
    int MSB = 31 - __builtin_clz(k);
    k ^= (1 << MSB);                // turns off the MSB

    if(up[x][MSB] == -1) return -1;
    return find(up[x][MSB], k);
}

// O(logn*logn)
int lca(int u, int v) {
    if(lvl[u] < lvl[v]) 
        swap(u, v);
    // now lvl[u] >= lvl[v]

    // First we go to equal levels, i.e to min(lvl[u], lvl[v]) = lvl[v] by making a jump of diff from u up the tree
    int diff = lvl[u] - lvl[v];
    u = find(u, diff);          // it may happen that u itself is lca now
    // now lvl[u] = lvl[v] -> this does not affect the lca of original u, v

    // Binary search on the level of lca now(not directly on the lca). We do binary search on how many levels up the level of u(or v) will the lca be
    int l = -1, r = lvl[u];     // r stores the answer, because obviously root is common ancestor
    while(r > l + 1) {
        int mid = (l + r) / 2;
        int l1 = find(u, mid), l2 = find(v, mid);
        if(l1 == l2) {
            r = mid;
        } else {
            l = mid;
        }
    }
    // return the node r levels up the u(or v) => lca(u, v)
    return find(u, r);
}

int main() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int x;          // x is parent of i
        cin >> x;
        adj[x].push_back(i);
    }

    memset(up, -1, sizeof up);
    // root = 1
    binary_lifting(1, -1);

    // total = O(q*logn*logn)
    forr(i, 0, q) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}