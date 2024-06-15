#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

// idea is to run multi source bfs and set the level of each cell as visited by monsters
// now run bfs from A and check if the level of A for a particular cell is less than level of that cell as visited by monsters. If yes, then we can visit that cell.



void solve() {
    int n, m;
    cin >> n >> m;
    char map[n][m];
    vector<pair<int, int>>monsters;
    int si, sj;
    forr(i, 0, n) {
        forr(j, 0, m) {
            cin >> map[i][j];
            if(map[i][j] == 'A') {
                si = i; sj = j;
            } else if(map[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }
    queue<pair<int ,int>>q1, q2;
    bool vis[n][m];
    int level[n][m];
    // memset(level, 0, sizeof(level));
    forr(i, 0, n) forr(j, 0, m) level[i][j] = (int)1e8;
    memset(vis, false, sizeof(vis));
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    forr(i, 0, monsters.size()) {
        int x = monsters[i].first, y = monsters[i].second;
        q2.push({x, y});
        level[x][y] = 0;
        vis[x][y] = true;
    }
    while(!q2.empty()) {
        pair<int, int> u2 = q2.front(); q2.pop();
        for(auto move : dirs) {
            int x = u2.first + move.first, y = u2.second + move.second;
            if(x < 0 || x >=n || y < 0 || y >= m) continue;
            if(vis[x][y] || map[x][y] == '#') continue;
            vis[x][y] = true;
            q2.push({x, y});
            level[x][y] = level[u2.first][u2.second] + 1;
        }
    }
    int level2[n][m];
    bool vis2[n][m];
    char way[n][m];
    memset(way, ' ', sizeof(way));
    memset(level2, 0, sizeof(level2));
    memset(vis2, false, sizeof(vis2));
    q1.push({si, sj});
    vis2[si][sj] = true;
    bool flag = false;
    int ei, ej;
    while(!q1.empty()) {
        pair<int, int>u1 = q1.front(); q1.pop();
        bool flag2 = false;
        for(auto move : dirs) {
            int x = u1.first + move.first, y = u1.second + move.second;
            if(x < 0 || x >=n || y < 0 || y >= m) continue;
            if(vis2[x][y] || map[x][y] != '.') continue;
            level2[x][y] = level2[u1.first][u1.second] + 1;
            if(level2[x][y] < level[x][y]) {
                vis2[x][y] = true;
                q1.push({x, y});
                if(move.first == -1) way[x][y] = 'U';
                else if(move.first == 1) way[x][y] = 'D';
                else if(move.second == 1) way[x][y] = 'R';
                else if(move.second == -1) way[x][y] = 'L';
                if(x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                    flag = true;
                    flag2 = true;
                    ei = x; ej = y;
                    break;
                }

            }
        }
        if(flag2) break;
    }
    if(si == 0 || si == n - 1 || sj == 0 || sj == n - 1) {
        flag = true;
        ei = si; ej = sj;
    }
    if(!flag) {
        cout << "NO";
    } else {
        cout << "YES\n";
        cout << level2[ei][ej] << '\n';
        int i = ei, j = ej;
        string s = "";
        while(i != si || j != sj) {
            s.push_back(way[i][j]);
            if(way[i][j] == 'U') i++;
            else if(way[i][j] == 'D') i--;
            else if(way[i][j] == 'L') j++;
            else if(way[i][j] == 'R') j--;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}