#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

int up[(int)2e5 + 10][20];      // up[u][x] = 2^x levels up ancestor of u
vector<int>adj[(int)2e5 + 10];
int n, q;

// binary_lifting(u, par) fills the array "up" with its ancestors 1,2,4,8,16.. level up the hierarchy
void binary_lifting(int u, int par) {
    up[u][0] = par;             // 2^0 levels up is parent itself
    for(int i = 0; i < 20; i++) {
        if(up[u][i - 1] != -1)
            up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for(int v : adj[u]) {
        if(v != par) {
            binary_lifting(v, u);
        }
    }
}

// finds ancestor of x, k levels up the tree
int find(int x, int k) {
    if(k == 0) return x;            // 0 levels up is x itself
    // k = (1011) = 2^3 + 2^1 + 2^0 = find 2^3 levels up from current and from there find 2^1 levels up from there and from there find 2^0 levels up from there.
    int MSB = 31 - __builtin_clz(k);
    k ^= (1 << MSB);                // turns off the MSB

    if(up[x][MSB] == -1) return -1;
    return find(up[x][MSB], k);
}

int main() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int x;          // x is parent of i
        cin >> x;
        adj[x].push_back(i);
    }
    memset(up, -1, sizeof up);

    // WLOG let root = 1
    binary_lifting(1, -1);
    forr(i, 0, q) {
        int x, k;
        cin >> x >> k;
        cout << find(x, k) << '\n';
    }
    return 0;
}