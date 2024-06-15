// Given a Tree of n vertices numbered from 1 to n. Each edge is associated with some weight given by array tree_weight. There are q queries in the form of a 2-D array, queries, where each element consist of two integers (say, u and v). For each query, compute the sum of bitwise XOR, the bitwise AND, and the bitwise OR of the weights of the edges on the path from u->v. Return the answer to each query as an array of integers.

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int from[N], to[N], weight[N];
vector<pair<int, int>> adj[N];
int up[N][21], lvl[N], par[N];
int bit[N][21];     // bit[i][j] -> number of nodes in path from i->1 with jth bit set.
// bit[1][j] = (1<<j) & w[1] ? 1 : 0 
// bit[i][j] = ((1<<j) & w[i] ? 1 : 0) + bit[parent[i]][j]
// we will carry out the xor, and, or and its sum for each bit

void binary_lifting(int u, int par) {
    up[u][0] = par;
    for(int i = 1; i < 21; i++) {
        if(up[u][i - 1] == -1) break;
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for(auto v : adj[u]) {
        if(v.first == par) continue;
        lvl[v.first] = 1 + lvl[u];
        binary_lifting(v.first, u);
    }
}

int find(int u, int k) {
    if(k == 0) return u;
    int msb = 31 - __builtin_clz(k);
    k ^= (1 << msb);
    if(up[u][msb] == -1) return -1;
    return find(up[u][msb], k);
}

int LCA(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    int diff = abs(lvl[u] - lvl[v]);

    u = find(u, diff);
    if(u == v) return u;

    for(int i = 20; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}


int solve(int u, int v) {
    int lca = LCA(u, v);
    int ans = 0;
    for(int j = 0; j < 21; j++) {
        int bits = bit[u][j] + bit[v][j] - 2 * bit[lca][j];
        int total_nodes = lvl[u] + lvl[v] - 2 * lvl[lca] + 1;
        int x, a, o;
        x = (bits % 2);
        o = (bits > 0);
        if(bits == total_nodes) a = 1;
        else a = 0;
        ans += (1 << j) * x + (1 << j) * a + (1 << j) * o;
    }

    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> from[i];
    for(int i = 0; i < m; i++) cin >> to[i];
    for(int i = 0; i < m; i++) cin >> weight[i];

    for(int i = 0; i < m; i++) {
        par[to[i]] = from[i];
        adj[from[i]].push_back({to[i], weight[i]});
        adj[to[i]].push_back({from[i], weight[i]});
    }

    memset(up, -1, sizeof up);
    // make the tree rooted at 1
    binary_lifting(1, -1);

    for(int j = 0; j < 21; j++) {
        bit[1][j] = 0;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 21; j++) {
            int w = adj[par[i]][i].second;
            bit[i][j] = ((1 << j) & w ? 1 : 0) + bit[par[i]][j];
        }
    }


    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }

    return 0;
}