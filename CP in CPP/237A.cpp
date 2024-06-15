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



//--------------SOLVE---------------//
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    forr(i,n){
        int x,y;
        cin>>x>>y;
        v[i].first=x;
        v[i].second=y;
    }
    pair<int,int>p=v[0];
    int maxcount=0,count=0;
    forr1(i,v.size()){
        if(v[i]==p){
            count++;
        }
        else{
            p=v[i];
            count=0;
        }
        maxcount=max(maxcount,count);
    }
    cout<<maxcount+1;
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
