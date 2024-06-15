#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m,r,c;
        cin >> n >> m >> r >> c;
        int d = 0, e = 0;
        vector<vector<char>>v(n, vector<char>(m, 'a'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
                if(v[i][j] == 'B') d = 1;
            }
        }
        for(int j = 0; j < m; j++){
            if(v[r - 1][j] == 'B'){
                e = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(v[i][c - 1] == 'B'){
                e = 1;
            }
        }
        if(v[r - 1][c - 1] == 'B') e = 2;
        if(d == 1){
            if(e == 2){
                cout << 0 << '\n';
            }
            else if(e == 1){
                cout << 1 << '\n';
            }
            else{
                cout << 2 << '\n';
            }
        }
        else{
            cout << -1 << '\n';
        }
        
    }
    
    return 0;
}