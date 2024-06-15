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

    //SEE TUTORIAL

    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    forr(i,n) cin>>a[i];
    vector<int>l(m);
    forr(i,m) cin>>l[i];
    vector<int>ans(n);
    int hash[100001]={0};
    vector<int>newa(n);
    ans[n-1]=1;
    hash[a[n-1]]=1;
    for(int i=n-2;i>=0;i--){
        if(hash[a[i]]==0){
            newa[i]=1;
        }
        else{
            newa[i]=0;
        }
        hash[a[i]]++;
        ans[i]=ans[i+1]+newa[i];
    }
    forr(k,m){
        cout<<ans[l[k]-1]<<endl;
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
