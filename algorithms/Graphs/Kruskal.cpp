#include<bits/stdc++.h>
using namespace std;
// Kruskal's algorithm fails for directed graph, because in DAG, kruskal's wrongly assumes there's cycle by union find method.

const int N = 1e6;
int Parent[N];
int Size[N];

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

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges;        // {weight, {u, v}} so that we can sort by weight
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});       // undirected graph
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < V; i++) make(i);     // 0 based indexing, takes nodes 0,1,2,3...
    int total_weight = 0;
    for(int i = 0; i < E; i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        total_weight += w;
        Union(u, v);
    }
    cout << total_weight << '\n';

    return 0;
}


// 6 9
// 0 1 1
// 0 2 5
// 1 2 2
// 1 4 1
// 2 4 2
// 1 3 2
// 3 4 3
// 3 5 1
// 4 5 2


//         1 ----------- 3
//      /  |  \          | \
//    0    |    \        |   5
//      \  |       \     | /
//         2 ----------- 4


