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
    vector<int>a(n);
    int maxi=-1000,mini=1000;
    forr(i,n) {
        cin>>a[i];
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    cout<<maxi<<" ";
    sort(a.begin(),a.end(),greater<ll>());
    sort(a.begin()+1,a.begin()+n-1);    //lexicographically smallest: increasing order sorting of middle numbers.
    for(int i=1;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<mini;
    
}




int main()
{
    // cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
