#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int>p(n);
    for(int i = 0; i < n ; i++) cin >> p[i];
    sort(p.begin(), p.end(), greater<int>());
    int j = n - 1, ans =  0;
    for(int i = 0; i <= j; i++){
        if(p[i] + p[j] <= x){
            j--;        // 7 7 7 7 1
        }
        ans++;
    }

    cout << ans;

    return 0;
}