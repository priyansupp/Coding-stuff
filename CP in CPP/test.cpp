#include<bits\stdc++.h>

using namespace std;
const int N = 1e5;
// bool vis[N];
// void bfs(vector<int> adj[], int S) {
//     queue<int>q;
//     q.push(S);
//     vis[S] = true;
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for(int v : adj[u]) {
//             if(vis[v]) continue;
//             q.push(v);
//             vis[v] = true;
//         }
//     }
//     return;
// }

// int distributionRanges(vector<vector<int>> ranges) {
//     int nodes = ranges.size();
//     vector<int>adj[nodes];
//     for(int i = 0; i < nodes; i++) {
//         for(int j = i + 1; j < nodes; j++) {
//             if(ranges[i][0] <= ranges[j][0] && ranges[i][1] >= ranges[j][0]) {
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             } else if(ranges[i][1] >= ranges[j][1] && ranges[i][0] <= ranges[j][1]) {
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             }
//         }
//     }
//     int count = 0;
//     for(int i = 0; i < nodes; i++) {
//         if(!vis[i]) {
//             bfs(adj, i);
//             count++;
//         }
//     }
//     return count * (count - 1);
// }

bool dfs(int &currank, vector<int>adj[], int v, int r, vector<bool> &vis) {
    if(v == r) {
        return true;
    }

    vector<int>ans;

    for(int k : adj[r]) {
        if(vis[k]) continue;
        ans.push_back(k);
    }

    sort(ans.begin(), ans.end());
    for(int u : ans) {
        vis[u] = true;
        if(dfs(++currank, adj, v, u, vis)) {
            currank--;
            return true;
        }
        currank--;
    }


    return false;
}

vector<int> lexdfs(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> r, vector<int> v) {
    vector<int>adj[g_nodes];
    for(int i = 0; i < g_from.size(); i++) {
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }
    vector<int>ans;
    for(int i = 0; i < r.size(); i++) {
        vector<bool>vis(g_nodes, false);
        int currank = 0;
        bool t = dfs(currank, adj, v[i], r[i], vis);
        ans.push_back(currank);
    }

    return ans;
}

int main()
{
    // vector<vector<int>> ranges = {
    //     // {1, 5}, {3, 8}, {10, 15}, {13, 14}, {20, 100}
    //     // {1, 3}, {2, 5}, {4, 8}, {10, 20}
    //     {208, 416}, {305, 1287}, {100, 405}
    // };

    // cout << distributionRanges(ranges);
    int g_nodes = 4;
    vector<int> g_from = {0, 1, 2, 3};
    vector<int> g_to = {1, 2, 3, 0};
    vector<int> r = {0};
    vector<int> v = {2};
    vector<int>ans = lexdfs(g_nodes, g_from, g_to, r, v);
    for(int i : ans) cout << i << '\n';

}