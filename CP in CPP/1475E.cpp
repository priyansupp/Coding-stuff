#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define forr(i,n) for(ll i=0;i<n;i++)
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define srtpairbysec(v) sort(v.begin(),v.end(),sortbysec)
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
const ll MOD=1e9+7;
ll __=1;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negatuve result, so gotta add b.
        ret += b;
    return ret;
}

int nCr(int n, int r) {    //using dp to calculate nCr mod p.
    if (r > n - r)
        r = n - r;
    int C[r + 1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++) {
 
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % MOD;
    }
    return C[r];
}

//--------------SOLVE--------------//
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    forr(i,n) cin>>a[i];
    srt(a);
    rev(a);
    int last = a[k-1];
    int t=0,in=0;
    forr(i,n) {
        if(i<k && a[i] == last) in++;
        if(a[i] == last) t++;
    }
    // output is t(C)in
    // cout<<k<<" "<<a[k-1]<<" "<<last<<" "<<t<<" "<<in<<endl;
    cout<<nCr(t,in)<<endl;
    
}

// 10 5
// 7 7 4 4 4 4 3 1 1 1


int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
