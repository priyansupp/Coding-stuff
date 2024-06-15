#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

// look at the problem in another way, 
// matching is defined as set of edges such that no two edges in the set share a common node.
// hence if I have taken a node, I cannot take that node again

// FOR Binary tree:
// greedy approach is to always choose the leaf edge(and disconnect the edges choosen and then further choose leaf edges from new graphs formed).
// greedy works because if any graph with maximum matching does not have leaf edge, then either we can switch second last leaf edge to leaf edge or if the second last leaf edge is not included we can include the leaf edge and increase the maximum matching
// for greedy, make a postorder traversal and keep finding maximum matching way up. 

// but in this question, we are given a general tree, so better is to use a dp approach
// instead of edge, we can look at the node being included or excluded from the matching. Each node can be included in only one edge

// dp(node, 0) => look only at subtree rooted at node and find maximum matching such that we don't select any edge that includes u
// dp(node, 1) => look only at subtree rooted at node and find maximum matching such that we do select exactly one edge that includes u

// ans[node] = max(dp[node][0], dp[node][1])
// final answer = ans[root]

// Let node has k children: c1,c2...ck 
// Let prefix[i] = ans[c1] + ans[c2] + ... + ans[ci]
// Let suffix[i] = ans[ci] + ans[ci+1] + ... + ans[ck]
// dp[node][0] = sum(ans[ci]) = suffix[0]  => each subtree of node is independent of eachother
// dp[node][1] = #(include "node" in exactly one of its children) = max(dp[ci][1] + sum(dp[node->otherChildren][0]))       if we include curr node in maximum matching then we can include all but only one children
//             = 1 + max(ans[c1]+...+ans[ci-1]) + dp[ci][0] + ans[ci+1]+...ans[ck]))    -> this denotes that we have chosen the edge node->ci to include node(and thus ci), hence for c1...ci-1 we can taken maximum by including or not including c1...ci-1 in their subtree respectively. Similarly for ci+1...ck. But for ci, as we have already chosen edge node->ci, hence ci has already been included, thus we cannot include ci in its subtree, hence add only dp[ci][0].
//             = 1 + prefix[i-1] + dp[ci][0] + suffix[i+1]

int dp[(int)2e5 + 10][2];
int ans[(int)2e5 + 10];
vector<int>adj[(int)2e5 + 10];
int n;

void solve(int u, int par) {
    bool leaf = true;
    vector<int>prefix, suffix;
    for(int v : adj[u]) {
        if(v == par) continue;
        leaf = false;
        solve(v, u);
        prefix.push_back(ans[v]);
        suffix.push_back(ans[v]);
    }

    if(leaf) return;

    int k = prefix.size();
    for(int i = 1; i < k; i++) prefix[i] += prefix[i - 1];
    for(int i = k - 2; i >= 0; i--) suffix[i] += suffix[i + 1];

    dp[u][0] = suffix[0];
    int i = 0;
    for(int v : adj[u]) {
        if(v == par) continue;
        int x = 1 + (i - 1 < 0 ? 0 : prefix[i - 1]) + dp[v][0] + (i + 1 >= k ? 0 : suffix[i + 1]);
        dp[u][1] = max(dp[u][1], x);
        i++;
    }

    ans[u] = max(dp[u][0], dp[u][1]);
}

void solve() {
    cin >> n;
    forr(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // WLOG, let root = 1
    solve(1, -1);
    cout << ans[1];
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}