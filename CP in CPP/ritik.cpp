// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     int n = s.length();
//     vector<vector<int>>L(n, vector<int>(n, 1));

//     int k;
//     for (int j = 2; j <= n; j++)
//     {
//         for (int i = 0; i < n - j + 1; i++)
//         {
//             k = i + j - 1;

//             if (s[i] == s[k] && j == 2) L[i][k] = 2;
//             else if (s[i] == s[k]) L[i][k] = L[i + 1][k - 1] + 2;
//             else L[i][k] = max(L[i][k - 1], L[i + 1][k]);
//         }
//     }

//     cout << s.length() - L[0][n - 1];
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
vector<int>fact;

void findFact(int n){
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n / i == i){
                fact.push_back(i);
            }else{
                fact.push_back(i);
                fact.push_back(n / i);
            }
        }
    }
}

int main()
{
    vector<pair<int, int>>v;
    while(1){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        char c;
        cin >> c;
        if(c != ','){
            break;
        }
        // cin >> c;
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}

