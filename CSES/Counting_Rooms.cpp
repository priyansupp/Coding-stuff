#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;
    char map[n][m];
    forr(i, 0, n) {
        forr(j, 0, m) cin >> map[i][j];
    }
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    int count = 0;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    forr(i, 0, n) {
        forr(j, 0, m) {
            if(vis[i][j] || map[i][j] == '#') continue;
            count++;
            queue<pair<int, int>>q;
            q.push({i, j});
            vis[i][j] = true;
            while(!q.empty()) {
                auto u = q.front(); q.pop();
                for(auto move : dirs) {
                    int x = u.first + move.first, y = u.second + move.second;
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(map[x][y] == '#' || vis[x][y]) continue;
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
    }
    cout << count;
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}