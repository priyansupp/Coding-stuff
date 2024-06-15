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
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007



//--------------SOLVE---------------//
void solve(){ 
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,int>mp;
    forr(i,n){
        mp[s[i]]=0;
    }
    forr(i,n){
        mp[s[i]]++;
    }
    vector<int>v;
    forr(i,mp.size()){
        v.pb(mp[s[i]]);
    }
    sort(v.begin(),v.end(),greater<ll>());
    // forr(i,v.size()) cout<<v[i]<<"&&";
    int card=0,money=0,i;
    int c=0;
    for(i=0;i<v.size();i++){
        card+=v[i];
        if(card>k){
            c=1;
            break;
        }
        money+=v[i]*v[i];
    }
    // cout<<money<<"**"<<card<<"**";
    if(c==1){
        int hehe=k-(card-v[i]);
        money+=hehe*hehe;
    }
    cout<<money;
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
