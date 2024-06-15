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

//--------------SOLVE--------------//

void solve(){
    int t, sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    string s;
    cin>>s;
    int time=0;
    int hor=ex-sx;
    int ver=ey-sy;
    int i=0;
    while(hor!=0 || ver!=0){
        if(s[i]=='N'){
            if(ver>0){
                ver--;
            }
            time++;
        }
        else if(s[i]=='S'){
            if(ver<0) ver++;
            time++;
        }
        else if(s[i]=='E'){
            if(hor>0) hor--;
            time++;
        }
        else if(s[i]=='W'){
            if(hor<0) hor++;
            time++;
        }
        i++;
        if(i==s.length()) break;
    }
    if(hor==0 && ver==0) cout<<time;
    else cout<<-1;
}




int main()
{
    // cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
