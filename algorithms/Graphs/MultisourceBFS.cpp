#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
const int N = 1e3;
bool visited[N][N];
int level[N][N];
int a[N][N];
int n, m;
vector<pair<int, int>>movements = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};
// Multisoucre bfs is used when there are multiple sources and it is required to reach a node the quickest by any of the source(just get minimum time/ShortesPath to reach a given node).
// We begin by pushing all the sources(s1, s2, s3...) nodes in queue and operating bfs just like usual. This works because for any given node, either s1 or s2 or s3... will reach there first and make assign to its level[node] and make the node visited, hence can not be visited by any other source changing its level.

//----------------------------------------- FUNCTIONS-------------------------------------------------//

bool isValid(int x,  int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(vector<pair<int, int>> &S){
    queue<pair<int, int>>q;
    for(auto s : S){
        q.push({s.first, s.second});
        visited[s.first][s.second] = true;
    }
    int ans = 0;
    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        int ux = u.first, uy = u.second;
        ans = max(ans, level[ux][uy]);  // minimum time is maximum time(maximum SP) to reach all the nodes.
        for(auto move : movements){
            int vx = ux + move.first;
            int vy = uy + move.second;
            if(!isValid(vx, vy)) continue;
            if(!visited[vx][vy]){
                q.push({vx, vy});
                visited[vx][vy] = true;
                level[vx][vy] = level[ux][uy] + 1;
            }
        }
    }
    return ans;
}

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }
}

// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    cin >> n >> m;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            maxi = max(maxi, a[i][j]);
        }
    }
    vector<pair<int, int>>source;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == maxi){
                source.push_back({i, j});
            }
        }
    }
    cout << bfs(source) << '\n';
    reset();
    return;
}




int main()
{
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}
