#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int color[N];
int ones = 0;
int twos = 0;

bool checkBipart(int S, vector<int>adj[]) {
    queue<int>q;
    q.push(S);
    color[S] = 1;
    ones++;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(color[v] == 0) {
                color[v] = (color[u] == 1) ? 2 : 1;
                if(color[v] == 1) ones++;
                else twos++;
                q.push(v);
            } else if(color[v] == color[u]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>adj[n + 1];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool flag = true;

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            if(!checkBipart(i, adj)) {
                cout << "-1";
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        cout << ones << '\n';
        for(int i = 1; i <= n; i++) {
            if(color[i] == 1) cout << i << " ";
        }
        cout << '\n' << twos << '\n';
        for(int i = 1; i <= n; i++) {
            if(color[i] == 2) cout << i << " ";
        }
    }


    return 0;
}