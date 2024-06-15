#include<bits/stdc++.h>
using namespace std;

// USED IN SINGLE SOURCE MULTIPLE DESTINATION TYPE QUESTIONS(FINDING SP FOR ALL DESTINATIONS FROM SINGLE SOURCE).
// SHORTEST PATH IN WEIGHTED GRAPH(directed/undirected). Does not works for negative edge weight(s) in undirected or directed graph. Edge weights must always be positive.(and obviously doesn't work for negative cycles)
const int N = 1e5;
vector<int>dist(N, INT_MAX);


// The following check works as the visited array only. Nodes whose dist value is correctly calculated(it is when the node is popped out of pq) won't pass this is condtn and hence won't be pushed again in pq.
void relax(int u, int v, int w, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq){
    if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
    }
}


void Dijkstras(int Source, vector<pair<int, int>>adjList[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;  // {distfromsource, node}, stores the {dist, node} in increasing order of dist from the source node.
    multiset<pair<int, int>>st;     // we can use multiset instead of pq, it'll work just fine. For a particular pair {3, 4} we need to process it only once.
    dist[Source] = 0;          // distance from source to source is 0
    pq.push({0, Source});      // distance from source to source is 0
    while(!pq.empty()){
        pair<int, int> parNode = pq.top();        // u is a pair with {distfromsource, node}.
        pq.pop();
        int u = parNode.second;
        if(dist[u] < parNode.first) continue;     // if distance has been further reduced since its last push in pq, then don't minimize using this {dist,u} pair
        // pq has node pair with lowest pathweight from source to u and thus we reach every other node v (from adjList of u), trying to minimize the distance from dist[u] + w(u->v)
        for(pair<int, int> childNode : adjList[u]){     // childNode = {v, weight}; here weight is the weight of the path from u to v.
            int v = childNode.first, w = childNode.second;
            relax(u, v, w, pq);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adjList[V + 1];
    for(int i = 0; i < E; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});       // comment it for directed graph
    }
    int source = 1;
    Dijkstras(source, adjList);     // SPath contains minimum weight of path to reach from source to any vertex. Source here is node[0]
    for(int i = 1; i <= V; i++){
        cout << "Shortest path from node " << source << " to node " << i << " is " << dist[i] << '\n';
    }

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




// Recall that in Dijkstra's algorithm, once a vertex is marked as "closed" (and out of the open set) - the algorithm found the shortest path to it, and will never have to develop this node again - it assumes the path developed to this path is the shortest.

// But with negative weights - it might not be true. 
//        A
//       / \
//      /   \
//     5     2
//    /       \
//   /         \
//   B--(-10)---C

// Dijkstra's will enter infinite loop for this one

// Similarly in this
// 6 7
// 0 1 1
// 0 2 2
// 1 3 2
// 2 4 3
// 3 4 4
// 3 5 1
// 4 5 -20


//         1 ----------- 3
//      /                | \
//    0                  |   5
//      \                | /
//         2 ----------- 4



