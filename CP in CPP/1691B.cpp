#include<bits/stdc++.h>
using namespace std;

int p[(int)1e5 + 100];

void rotate(int i, int j){
    p[i] = j;
    for(int k = i + 1; k <= j; k++){
        p[k] = k - 1;
    }
}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n + 1);
        for(int i = 1; i <= n; i++) cin >> s[i];
        if(n == 1){
            cout << "-1\n";
            continue;
        }
        bool flag = true;
        for(int i = 1; i <= n; ){
            int j = i + 1;
            while(s[j] == s[i] && j <= n){
                j++;
            }
            if(j == i + 1){
                cout << "-1\n";
                flag = false;
                break;
            }
            rotate(i, j - 1);
            i = j;
        }
        if(flag){
            for(int i = 1; i <= n; i++)
            cout << p[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}