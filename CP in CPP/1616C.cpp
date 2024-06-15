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

ll modulus(ll a, ll b){
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
    forr(i,n) cin>>a[i];
    int maxcount=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double cd=(double)(a[j-1]-a[i-1])/(double)(j-i);
            int count=2;                //a[i-1] & a[j-1] are already counted as terms of AP.
            for(int k=j+1;k<=n;k++){    //we could have started with k=1 but we did from j+1 tp optimise.
                double cd1=(double)(a[k-1]-a[j-1])/(k-j);
                if(cd==cd1) count++;
            }
            maxcount=max(maxcount,count);
        }
    }
    cout<<n-maxcount<<endl;
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
