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
    ll sum = 0, res = 0;    // sum <= s always
    for(int r = 0; r < n; r++){      // logic is to calculate all good segments for a particular r and iterate r from start to end
        sum += a[r];
        while(sum > s){
            sum -= a[l++];
        }
        res += r - l + 1;    // for a given good segment from [l...r] all the subsegments from [i...r] for all i from l,l+1,l+2,....r will also be a good segment to consider.
    }

    cout << res << '\n';

    return 0;
}