#include <bits/stdc++.h>

using namespace std;
using std::string;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007

ll MOD(ll a, ll b) {
    ll ret = a % b;
    if (ret < 0)    //for handling negative results
        ret += b;
    return ret;
}

//--------------SOLVE---------------//
void solve(){
    ll x,y;
    cin>>x>>y;
    ll n;
    cin>>n;
    ll res[6]={x,y,y-x,-x,-y,x-y};
    switch(n%6){
        case 0:
            cout<<MOD(res[5],mod);
            break;
        case 1:
            cout<<MOD(res[0],mod);
            break;
        case 2:
            cout<<MOD(res[1],mod);
            break;
        case 3:
            cout<<MOD(res[2],mod);
            break;
        case 4:
            cout<<MOD(res[3],mod);
            break;
        case 5:
            cout<<MOD(res[4],mod);
            break;
    }
    
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
