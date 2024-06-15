#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    long long n, s;
    cin >> n >> s;
    vector<long long>a(n);
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    
    int l = 0;
    ll sum = 0, res = 0;    // sum >= s always
    for(int r = 0; r < n; r++){      // logic is to calculate all good segments for a particular r and iterate r from start to end
        sum += a[r];
        while(sum - a[l] >= s){
            sum -= a[l];
            l++;
        }

        if(sum >= s) res += l + 1;              // If the segment a[l...r] is good (i.e sum >= s) then all the subsegments from [i..r] for all i from 0,1,2,...l will also be a good segment to consider.
    }

    cout << res << '\n';

    return 0;
}