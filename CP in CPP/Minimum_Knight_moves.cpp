#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/NAKANJ/

bool visited[8][8];
int level[8][8];
vector<pair<int, int>> movements = {
    {2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}
};

//----------------------------------------- FUNCTIONS-------------------------------------------------//
int getX(string s) {return s[0] - 'a';}
int getY(string s) {return s[1] - '1';}


bool validMove(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs(string s1, string s2){
    // A node is represented by {x, y} coordinates.
    int SX = getX(s1), SY = getY(s1);
    int DX = getX(s2), DY = getY(s2);

    queue<pair<int, int>>q;
    q.push({SX, SY});
    while(!q.empty()){
        pair<int, int> v = q.front();
        q.pop();
        int X = v.first, Y = v.second;
        for(pair<int, int> move : movements){       // bfs in matrix, discovering all possible positions we can go onto
            int ChildX = X + move.first, ChildY = Y + move.second;
            if(!validMove(ChildX, ChildY)) continue;
            if(!visited[ChildX][ChildY]){
                q.push({ChildX, ChildY});
                visited[ChildX][ChildY] = true;
                level[ChildX][ChildY] = level[X][Y] + 1;
            }
        }
    }
    return level[DX][DY];       // Shortest path from source to dest
}

void reset(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }
}

//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << bfs(s1, s2) << '\n';
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
