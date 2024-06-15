#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

vector<pair<ll, ll>> adj[2501];
ll shortest[2501], shortest2[2501];
ll par[2501];
int n, m;

int main() {
    // find the minimum cost path from 1->n by negating the weights.
    cin >> n >> m;
    forr(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
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

    // relax two more times
    bool flag = false;
    for(int u = 1; u <= n; u++) {
        for(pair<ll, ll> p : adj[u]) {
            ll v = p.first, w = p.second;
            if(shortest[u] != LLONG_MAX && shortest[v] > shortest[u] + w) {
                shortest[v] = shortest[u] + w;
                flag = true;
            }
        }
    }

    // no negative cycle
    if(!flag) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";

    int s, e;
    bool skip = 0;
    for(int u = 1; u <= n; u++) {
        for(pair<ll, ll> p : adj[u]) {
            ll v = p.first, w = p.second;
            if(shortest[u] != LLONG_MAX && shortest[v] > shortest[u] + w) {
                shortest[v] = shortest[u] + w;
                cout << u << ' ' << v << '\n';
                par[v] = u;
                if(!skip) {
                    e = v;
                    s = u;
                }
                skip = 1;
                break;
            }
        }
    }

    vector<int>ans;
    int t = e;
    ans.push_back(e);
    while(t != s) {
        ans.push_back(par[t]);
        t = par[t];
    }
    ans.push_back(e);
    for(int i : ans) cout << i << ' ';
    return 0;
}

