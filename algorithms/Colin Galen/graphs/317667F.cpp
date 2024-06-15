#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    bool flag = false;
    
    vector<int>adj[n + 1];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x == y) {
            flag = true;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(flag) {
        cout << -1;
        return;
    }
}

int main()
{
    solve();


    return 0;
}