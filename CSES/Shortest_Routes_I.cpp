#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(ll i = a; i < b; i++)

void relax(ll u, ll v, ll w, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > &pq, vector<ll> &ans) {
    if(ans[u] + w < ans[v]) {
        ans[v] = ans[u] + w;
        pq.push({ans[v], v});
    }
}

void dijkstra(vector<ll> &ans, vector<pair<ll, ll>> adj[], ll S) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;       // {weight, v}
    pq.push({0, S});
    ans[S] = 0;
    while(!pq.empty()) {
        pair<ll, ll> x = pq.top(); pq.pop();
        if(ans[x.second] < x.first) continue;           // some other guy already reduced the distance of node x.second(and hence all further nodes attached with it), hence with distance x.first which is more than prev, things won't improve
        for(pair<ll, ll> y : adj[x.second]) {
            ll u = x.second, v = y.first, w = y.second;
            relax(u, v, w, pq, ans);
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>>adj[n + 1];
    forr(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    // cout << 1;
    vector<ll>ans(n + 1, LLONG_MAX);
    dijkstra(ans, adj, 1);
    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
}


int main() {
    ll t = 1;
    while(t--) solve();
    return 0;
}