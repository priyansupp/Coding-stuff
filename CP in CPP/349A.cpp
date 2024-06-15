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
    vector<int>p(n);
    int a=0,b=0,c=0;
    int d=0;
    forr(i,n){
        cin>>p[i];
    }
    forr(i,n){
        if(p[i]==25){
            a++;
        }
        else if(p[i]==50 && a>0){
            b++;
            a--;
        }
        else if(p[i]==100 && (a>0 && b>0)){
            c++;
            a--;
            b--;
        }
        else if(p[i]==100 && a>2){
            c++;
            a-=3;
        }
        else{
            d=1;
            break;
        }
    }
    if(d==0) cout<<"YES";
    else cout<<"NO";
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
