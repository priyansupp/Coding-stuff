#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

int n, m;
vector<pair<int, int>> adj[(int)1e5 + 1];           // for forward edges
vector<pair<int, int>> adj2[(int)1e5 + 1];          // for reverse edges

void dijkstra(int S, vector<ll> &dist, int flag) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    pq.push({0, S});
    dist[S] = 0;
    while(!pq.empty()) {
        pair<ll, ll>nodeU = pq.top(); pq.pop();
        ll u = nodeU.second;
        if(dist[u] < nodeU.first) continue;             // optimises dijkstra
        vector<pair<int, int>> x;
        if(flag == 1) x = adj[u];
        else x = adj2[u];
        for(pair<int, int> nodeV : x) {
            ll w = nodeV.second, v = nodeV.first;
            if(nodeU.first + w < dist[v]) {
                dist[v] = nodeU.first + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    forr(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }
    vector<ll>dist1(n + 1, LLONG_MAX), distn(n + 1, LLONG_MAX);
    dijkstra(1, dist1, 1);
    dijkstra(n, distn, 2);
    // for(int i = 1; i <= n; i++) cout << dist1[i] << ' ';
    // cout << '\n';
    // for(int i = 1; i <= n; i++) cout << distn[i] << ' ';
    // cout << '\n';
    ll ans = LLONG_MAX;
    for(int u = 1; u <= n; u++) {
        for(pair<int, int> nodeV : adj[u]) {
            ll v = nodeV.first, w = nodeV.second;
            ll x1 = dist1[u], x2 = distn[v];                // u will always connect towards 1 and v will always connect towards n
            if(x1 != LLONG_MAX && x2 != LLONG_MAX) ans = min(ans, x1 + x2 + w / 2);
        }
    }
    cout << ans;
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}