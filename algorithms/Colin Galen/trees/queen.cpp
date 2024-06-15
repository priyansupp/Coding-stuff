#include<bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = a; i < b; i++)

vector<int>ans;

void dfs(vector<int> adj[], vector<int> &c, int u) {
    bool flag = (c[u] == 1);
    for(int v : adj[u]) {
        if(c[v] == 0) flag = false;
        dfs(adj, c, v);
    }
    if(flag) ans.push_back(u);                  // just remove all those which is itself 1 and all its children as 1. We don't need to rejoin the nodes, because we just care about 1's, so a->b->c, if node a,b,c has all children 1, so removing b and attaching c will keep this all children property 1 true for a
}

int main() {
    int n;
    cin >> n;
    vector<int>c(n + 1);
    vector<int>adj[n + 1];
    int S;
    forr(i, 1, n + 1) {
        int a, b;
        cin >> a >> b;
        if(a == -1) {
            S = i;
            continue;
        }
        adj[a].push_back(i);
        c[i] = b;
    }
    dfs(adj, c, S);
    sort(ans.begin(), ans.end());
    for(int x : ans) cout << x << ' ';
    if(ans.empty()) cout << -1;
    return 0;
}