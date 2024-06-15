#include<bits/stdc++.h>
using namespace std;

int Parent[1000000];
int Size[1000000];

void make(int v){
    Parent[v] = v;
    Size[v] = 1;
}

int find(int v){
    if(v == Parent[v]) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        Parent[b] = a;
        Size[a] += Size[b];
    }
}

int getMinimumCost(vector<int> color, vector<int> u, vector<int> v, vector<int> cost) {
    int n = color.size();
    int m = u.size();
    vector<vector<pair<int, int>>>adj(n);

    for(int i = 0; i < m; i++) {
        adj[u[i] - 1].push_back({v[i] - 1, cost[i]});
        adj[v[i] - 1].push_back({u[i] - 1, cost[i]});
    }

    // the idea is to remove all the color0 nodes and make new connections in the graph from all adjacent vertices of that node to all the other adjacent vertices. Then just take the MST of the newly created graph and find maximum edge weight in that.
    for(int i = 0; i < n; i++) {
        if(color[i] == 1) continue;
        for(pair<int, int> u : adj[i]) {
            for(pair<int, int> v : adj[i]) {
                if(u.first == v.first) continue;
                adj[u.first].push_back({v.first, u.second + v.second});
                adj[v.first].push_back({u.first, u.second + v.second});
            }
        }
        adj[i].clear();
    }

    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++) {
        for(pair<int, int> p : adj[i]) {
            edges.push_back({p.second, {p.first, i}});
        }
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < n; i++) {
        make(i);
    }

    int max_weight = 0;
    for(int i = 0; i < edges.size(); i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        max_weight = max(max_weight, w);
        Union(u, v);
    }
    return max_weight;
}

int main()
{
    int n;
    cin >> n;
    vector<int> color(n);
    for(int i = 0; i < n; i++) cin >> color[i];
    int conn;
    cin >> conn;
    vector<int> u(conn), v(conn), cost(conn);
    for(int i = 0; i < conn; i++) cin >> u[i];
    for(int i = 0; i < conn; i++) cin >> v[i];
    for(int i = 0; i < conn; i++) cin >> cost[i];

    cout << getMinimumCost(color, u, v, cost);

    return 0;
}