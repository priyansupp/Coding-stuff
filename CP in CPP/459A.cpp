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
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        if(y1==y2){
            cout<<-1;
            return;
        }
        int s=abs(y1-y2);
        if(x1+s>1000){
            cout<<x1-s<<" "<<y1<<" "<<x2-s<<" "<<y2;
        }
        else{
            cout<<x1+s<<" "<<y1<<" "<<x2+s<<" "<<y2;           
        }
    }
    else if(y1==y2){
        if(x1==x2){
            cout<<-1;
            return;
        }
        int s=abs(x1-x2);
        if(y1+s>1000){
            cout<<x1<<" "<<y1-s<<" "<<x2<<" "<<y2-s;
        }
        else{
            cout<<x1<<" "<<y1+s<<" "<<x2<<" "<<y2+s;           
        }
    }
    else{
        if(abs(x1-x2)!=abs(y1-y2)){
            cout<<-1;
            return;
        }
        cout<<x2<<" "<<y1<<" "<<x1<<" "<<y2;
    }
}




int main()
{
    // cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
