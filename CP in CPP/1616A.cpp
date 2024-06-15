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
    map<int,int>mp;
    forr(i,n) {
        int x;
        cin>>x;
        mp[abs(x)]++;    //At first, let's replace ai with |ai|. Let f(x) denote the number of vaues in the array equal to x after the replacement (or, equal to x or −x before).
    }
    int sum=0;
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if((*it).first==0){
            sum+=min(1,(*it).second);    // for the zero we can only get min(1,f(0)) different values.
        }
        else{
            sum+=min(2,(*it).second);    //And for any other number x>0, we can get min(2,f(x)) different numbers in the array.
        }
        
    }
    cout<<sum<<endl;
    
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
