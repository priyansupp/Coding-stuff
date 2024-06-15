#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int k; 
    cin >> k;
    vector<ll>left(k),right(k);
    for(int i = 0; i < k;i++) cin>>left[i]>>right[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < k; i++){
        int l = left[i];   // always counts in good
        int r = right[i];  // always counts in good
        // good segment is from [l...r]
        int lp = 0;
        int rp = n - 1;
        while(a[lp] < l && rp > lp + 1){
            int m = (lp + rp)/2;
            if(a[m] > l){
                rp = m;
            }
            else{
                lp = m;    // contains where a[lp] == l
            }
        }
        int lbound;
        if(a[lp] == l) lbound = lp;
        else lbound = lp + 1;

        lp = 0;
        rp = n - 1;
        while(a[rp] > r && rp > lp + 1){
            int m = (lp + rp)/2;
            if(a[m] < r){
                lp = m;
            }
            else{
                rp = m;   // contains when a[rp] == r
            }
        }
        int rbound = rp;
        if(a[rp] == r) rbound = rp;
        else rbound = rp - 1;

        if(rbound >= lbound) cout << rbound - lbound + 1 << " ";
        else cout << 0 << " ";
    }
    
    return 0;
}