#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

int dfs(vector<int> adj[], int u, int count[]) {
    int ans = 0;
    for(int v : adj[u]) {
        ans += dfs(adj, v, count);
    }
    count[u] = ans;
    return ans + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int>adj[n + 1];
    forr(i, 2, n + 1) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    int count[n + 1];
    memset(count, 0, sizeof(count));
    dfs(adj, 1, count);
    for(int i = 1; i <= n; i++) cout << count[i] << ' ';
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}