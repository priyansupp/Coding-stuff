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

// finds ancestor of x, k levels up the tree : O(logn)
int find(int x, int k) {
    if(k == 0) return x;            // 0 levels up is x itself
    // k = (1011) = 2^3 + 2^1 + 2^0 = find 2^3 levels up from current and from there find 2^1 levels up from there and from there find 2^0 levels up from there.
    int MSB = 31 - __builtin_clz(k);
    k ^= (1 << MSB);                // turns off the MSB

    if(up[x][MSB] == -1) return -1;
    return find(up[x][MSB], k);
}

// find2(x, k) : iterative
int find2(int x, int k) {
    while(k) {
        int MSB = 31 - __builtin_clz(k);
        k ^= (1 << MSB);
        x = up[x][MSB];
        if(x == -1) return -1;
    }
    return x;
}


// O(logn)
int lca(int u, int v) {
    if(lvl[u] < lvl[v]) 
        swap(u, v);
    // now lvl[u] >= lvl[v]

    int diff = lvl[u] - lvl[v];
    u = find(u, diff);
    // now lvl[u] = lvl[v]

    // very important
    if(u == v) return u;        // we cannot make any jump in power of 2

    // Try to make the largest jumps in power of 2 such that after the jump we still don't reach lca(u, v)
    // If we can't make anymore jumps, that means we would be just below lca, and 1 more jump would give us lca.
    // Basically, if lvl[u]-lvl[lca] = x, then we try to go to x-1, by making jumps in power of 2 such that after jump Lu != Lv. This is possible because we can represent x-1 in sum of powers of 2.

    for(int i = 19; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return find(u, 1);      // or equivalently up[x][0]
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

    forr(i, 0, q) {
        int u, v;
        cin >> u >> v;
        // TC = O(q*logn)
        cout << lca(u, v) << '\n';
    }
    return 0;
}