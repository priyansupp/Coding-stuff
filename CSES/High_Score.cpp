#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

vector<pair<ll, ll>> adj[2501];
ll shortest[2501], shortest2[2501];
bool vis[2501];
vector<int>path;
int n, m;

bool dfs(int u) {
    vis[u] = 1;
    path.push_back(u);
    if(u == n) return true;
    for(pair<ll, ll> p : adj[u]) {
        ll v = p.first;
        if(vis[v]) continue;
        if(dfs(v)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    // find the minimum cost path from 1->n by negating the weights.
    cin >> n >> m;
    forr(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        // u->v with weight -w
        adj[u].push_back({v, -w});
    }

    // Bellman-ford works well with negative weight edges, and also detects for negative weight cycles
    for(int i = 0; i <= n; i++) shortest[i] = LLONG_MAX;
    shortest[1] = 0;
    for(int i = 1; i < n; i++) {
        // relax all the edges
        for(int u = 1; u <= n; u++) {
            for(pair<ll, ll> p : adj[u]) {
                ll v = p.first, w = p.second;
                if(shortest[u] != LLONG_MAX && shortest[v] > shortest[u] + w) {
                    shortest[v] = shortest[u] + w;
                }
            }
            // cout << u << ' ' << v << ' ' << shortest[u] << ' ' << shortest[v] << '\n';
        }
    }

    // we need shortest2 to check if any node on 1->n path can be relaxed or not. If some other part of graph can be relaxed but not the 1->n path then still my answer would be finite, as I only have to answer maximum for the path 1->n, not any arbitrary path.
    for(int i = 0; i <= n; i++) shortest2[i] = shortest[i];

    // relax n-1 more times
    for(int i = 1; i < n; i++) {
        for(int u = 1; u <= n; u++) {
            for(pair<ll, ll> p : adj[u]) {
                ll v = p.first, w = p.second;
                if(shortest2[u] != LLONG_MAX && shortest2[v] > shortest2[u] + w) {
                    shortest2[v] = shortest2[u] + w;
                }
            }
        }
    }

    dfs(1);
    // if any node in the path from 1 to n can be relaxed then we can get -inf path from 1->n
    for(ll i : path) {
        // cout << i << ' ';
        if(shortest2[i] < shortest[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << -shortest[n];
    return 0;
}

