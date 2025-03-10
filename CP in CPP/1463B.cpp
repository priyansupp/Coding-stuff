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
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define srtpairbysec(v) sort(v.begin(),v.end(),sortbysec)
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define input()         int n; cin>>n; vector<int>a(n); forr(i,n) cin>>a[i]
const ll MOD=1e9+7;
ll __=1;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);          //return (a.second > b.second);  for sorting in decreasing order by second element.
}

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negative result, so gotta add b.
        ret += b;
    return ret;
}

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    input();
    double sum = 0;
    forr(i,n) sum += a[i];
    ll res = sum/(n*2);
    vector<int>b1(n), b2(n);
    ll odd = 0, even = 0;

    // (a1,1,a3,1,a5,1,a7,1,.....) or (1,a2,1,a4,1,a6,1,....)  is one of the epossible array.
    // S = S_odd + S_even. therefore one out of S_odd and S_even will be <= S.
    // series b1 yields S_odd, series b2 yields S_even.

    forr(i,n){
        if(i%2 == 0){
            b1[i] = a[i];    //element values at odd places in b1
            b2[i] = 1;
        }
        else{
            b1[i] = 1;
            b2[i] = a[i];   //element values at odd places in b
        }
        odd += abs(a[i] - b1[i]);
        even += abs(a[i] - b2[i]);
    }
    if(odd > even){
        forr(i,n) cout<<b2[i]<<" ";
    }
    else{
        forr(i,n) cout<<b1[i]<<" ";
    }
    cout<<"\n";
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
