#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;
    char map[n][m];
    int si, sj, ei, ej;
    forr(i, 0, n) {
        forr(j, 0, m){
            cin >> map[i][j];
            if(map[i][j] == 'A') {
                si = i; sj = j;
            }
            if(map[i][j] == 'B') {
                ei = i; ej = j;
            }
        }
    }
    bool vis[n][m];
    int level[n][m];
    char way[n][m];
    memset(way, '.', sizeof(way));
    memset(level, 0, sizeof(level));
    memset(vis, false, sizeof(vis));
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>>q;
    q.push({si, sj});
    vis[si][sj] = true;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto move : dirs) {
            int x = u.first + move.first, y = u.second + move.second;
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(map[x][y] == '#' || vis[x][y]) continue;
            level[x][y] = level[u.first][u.second] + 1;
            // note: for a cell[x][y], way[x][y] denotes from where cell[x][y] has been reached earliest. i.e if way[x][y] = 'U' then the cell from have been reached from some cell below it(c[x-1][y] + 'U' = cell[x][y])
            // take care of i,j,x,y. Change in x actually gets you up and down, change in y actually get you left and right.
            // we can't build our way matrix using way[u.first][u.second], because it'll take into consideration which direction we first take.
            if(move.first == -1) way[x][y] = 'U';
            else if(move.first == 1) way[x][y] = 'D';
            else if(move.second == 1) way[x][y] = 'R';
            else if(move.second == -1) way[x][y] = 'L';
            q.push({x, y});
            vis[x][y] = true;
        }
    }
    // forr(i, 0, n) {
    //     forr(j, 0, m) cout << way[i][j] << " ";
    //     cout << '\n';
    // }
    if(vis[ei][ej]) {
        string s = "";
        int i = ei, j = ej;
        cout << "YES\n";
        cout << level[ei][ej] << '\n';
        while(i != si || j != sj) {
            s.push_back(way[i][j]);
            if(way[i][j] == 'L') j++;       // way[i][j] == 'L' means it has been reached from a cell from the right, whoose left is the cell(x, y), therefore move towards right.
            else if(way[i][j] == 'R') j--;
            else if(way[i][j] == 'U') i++;
            else if(way[i][j] == 'D') i--;
        }
        reverse(s.begin(), s.end());
        cout << s;
    } else {
        cout << "NO";
    }
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}