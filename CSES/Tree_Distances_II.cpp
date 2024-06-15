#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

ll dp[(int)2e5 + 10];
ll ans[(int)2e5 + 10];
ll nodes[(int)2e5 + 10];
vector<int>adj[(int)2e5 + 10];
int n;

// dp[c] = total distance from c to each node in subtree of c
// ans[c] = total distance from c to each node in the whole tree

// draw a subtree rooted at u with k children to observe the transitions:
// Let u has children c1,c2,..,ck
// dp[u] = sum(ni + dp[ci])  -> where ni = number of nodes in subtree ci

// REROOTING STEP => REROOT FROM u TO ci AND FIND THE ANSWER FROM ci : 
// ans[ci] = dp[ci] + ans[u] - (ni + dp[ci]) + (n - ni) = ans[u] + n - 2 * ni     -> where u is parent of u
// ans[u] - (ni + dp[ci]) => subtracting the contribution of ci subtree in ans[u]
// ans[u] - (ni + dp[ci]) + (n - ni) => adding 1 for each of remaining (n-ni) to get to ci

void solve(int u, int par) {
    nodes[u]++;
    for(int v : adj[u]) {
        if(v == par) continue;
        solve(v, u);
        dp[u] += nodes[v] + dp[v];
        nodes[u] += nodes[v];
    }
}

void solve2(int u, int par) {
    for(int v : adj[u]) {
        if(v == par) continue;
        ans[v] = ans[u] + n - 2 * nodes[v];
        solve2(v, u);
    }
}


int main() {
    cin >> n;
    forr(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // WLOG, let root = 1
    solve(1, -1);
    ans[1] = dp[1];
    solve2(1, -1);
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}