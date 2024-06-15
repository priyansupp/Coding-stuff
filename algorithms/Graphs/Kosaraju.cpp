// https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=54
// TO FIND AND PRINT ALL STRONGLY CONNECTED COMPONENT
// 1. SORT ALL THE VERTICES ACCORDING TO FINISHING TIME
// 2. REVERSE THE GRAPH
// 3. DO A DFS

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adjList[V];         // directed graph
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    return 0;
}