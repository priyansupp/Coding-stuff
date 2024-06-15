#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    multiset<int>h(n);
    vector<pair<int, int>>t(m);
    for(int i = 0; i < n ; i++) cin >> h[i];
    for(int i = 0; i < m ; i++) {
        cin >> t[i].first;
        t[i].second = i;
    }
    sort(t.begin(), t.end());
    
    for(int i = 0 ; i < m ; i++){
        int l = -1;            // h[l].first <= t[i], always good
        int r = h.size();     // h[r].first >  t[i], always bad
        while(l < r - 1){
            int mid = (l + r)/2;
            if(h[mid] <= t[i]){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(l != -1){
            cout << h[l] << '\n';
            vector<int>::iterator itr = find(h.begin(), h.end(), h[l]);
            h.erase(itr);
        }else{
            cout << -1 << '\n';
        }

    }
    
    return 0;
}