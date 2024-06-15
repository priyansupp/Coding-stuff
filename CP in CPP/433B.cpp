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
#define srt(v)         sort(v.begin(),v.end())
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
    vector<int>v(n);
    forr(i,n) cin>>v[i];
    vector<int>u(v);
    srt(u);

    int m;
    cin>>m;
    vector<ll>ans(m);

    vector<ll>sumvt1(n);
    sumvt1[0]=v[0];
    forr1(i,n){     //calculating the prefix sum of the sequence beforehand
        sumvt1[i]=v[i]+sumvt1[i-1];
    }

    vector<ll>sumvt2(n);
    sumvt2[0]=u[0];
    forr1(i,n){     //calculating the prefix sum of the sequence beforehand
        sumvt2[i]=u[i]+sumvt2[i-1];
    }

    forr(i,m){
        int type,l,r;
        cin>>type>>l>>r;
        if(l==1){
            if(type==1) ans[i]=sumvt1[r-1];
            else ans[i]=sumvt2[r-1];
            continue;
        }
        if(type==1){
            ans[i]=sumvt1[r-1]-sumvt1[l-2];
        }
        else{
            ans[i]=sumvt2[r-1]-sumvt2[l-2];
        }
    }
    forr(i,m) cout<<ans[i]<<endl;
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
