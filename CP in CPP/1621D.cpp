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
#define srt(v)          sort(v.begin(),v.end())
#define srtpairbysec(v) sort(v.begin(),v.end(),sortbysec)
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007
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

//--------------SOLVE---------------//
void solve(){
    int n;
    cin>>n;
    ll sum=0;
    vector<vector<ll>>c(2*n, vector<ll>(2*n,0));
    forr(i,2*n){
        forr(j,2*n) cin>>c[i][j];
    }

    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++) sum+=c[i][j];   //clearing snow from bottom right. REQUIRED
    }

    //Only one out of these snow covered positions is required to be cleared for all to get to bottom right(other positions will just increase the net cost). THINK GREEDILY. If friends at corners get to bottom then everyone would also be able to.
    //CHECK TUTORIAL
    vector<int>extrasnow;   //(2n,1) , (1,2n), (2n,n), (1,n+1), (n+1,n), (n,n+1), (n+1,1), (n,2n)
    extrasnow.pb(c[2*n-1][0]);
    extrasnow.pb(c[0][2*n-1]);
    extrasnow.pb(c[2*n-1][n-1]);
    extrasnow.pb(c[0][n]);
    extrasnow.pb(c[n][n-1]);
    extrasnow.pb(c[n-1][n]);
    extrasnow.pb(c[n][0]);
    extrasnow.pb(c[n-1][2*n-1]);
    sum+=minV(extrasnow);
    cout<<sum<<endl;
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
