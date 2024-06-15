#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n), dep(n);
    for(int i = 0; i < n ; i++) cin >> arr[i] >> dep[i];

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int ans = 1, j = 0, maxi = 1;
        
    for(int i = 1 ; i < n;){
        // cout << ans << '\n';
        if(arr[i] < dep[j]){
            ans++;
            i++;
        }else if(arr[i] > dep[j]){
            ans--;
            j++;
        }
        maxi = max(maxi, ans);
    }
    cout << maxi;
    
    return 0;
}