#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
bool vis[N];


int main()
{

    int n, m;
    cin >> n >> m;
    vector<int>adj[n + 1];
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        vector<int>friends;
        while(x--) {
            int y;
            cin >> y;
            friends.push_back(y);
        }
        // for a group of friends, we make only linear connections, not each possible combination, as in the end we just need to find number of nodes in a connected component
        for(int i = 1; i < friends.size(); i++) {
            adj[friends[i]].push_back(friends[i - 1]);
            adj[friends[i - 1]].push_back(friends[i]);
        }
    }

    vector<int>a(n + 1);        // contains the answer

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            queue<int>q;
            vector<int>comp;        // stores all the nodes in the component
            q.push(i);
            vis[i] = true;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                for(int v : adj[u]) {
                    if(vis[v]) continue;
                    q.push(v);
                    vis[v] = true;
                }
            }

            for(int x : comp) a[x] = comp.size();
        }
    }


    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}