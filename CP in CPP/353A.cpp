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
    vector<pair<int,int>>d(n);
    int u=0,l=0;
    forr(i,n){
        cin>>d[i].first>>d[i].second;
        u+=d[i].first;
        l+=d[i].second;
    }
    if(u%2==0 && l%2==0) cout<<0;
    else if(u%2!=0 && l%2==0) cout<<-1;
    else if(u%2==0 && l%2!=0) cout<<-1;
    else if(u%2!=0 && l%2!=0){
        forr(i,n){
            if(d[i].first%2==0 && d[i].second%2!=0){
                cout<<1;
                return;
            }
            else if(d[i].first%2!=0 && d[i].second%2==0){
                cout<<1;
                return;
            }
        }
        cout<<-1;
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
