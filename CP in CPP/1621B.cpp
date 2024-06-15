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
    int n;
    cin>>n;
    vector<pair<int,int>>lr(n);
    vector<int>c(n);
    forr(i,n){
        cin>>lr[i].first>>lr[i].second>>c[i];
    }
    
    int minL=INT_MAX,maxR=0,maxLen=0;
    int costL=INT_MAX, costR=INT_MAX,costLen=INT_MAX;
    for(int i=0;i<n;i++){

        if(lr[i].first<minL) minL=lr[i].first,costL=INT_MAX;   //The smallest integer in the shop. 
        //If lr[i].first<minL then lr[i].first==minL in next if condition and costL would be the cost of that segment(c[i]) which contained     lr[i].first(which is minimum). But if in some other segment lr[i].first==minL the second if statement would only be executed and new costL would be the minimum of the two segments containing minL.
        if(lr[i].first==minL) costL=min(costL,c[i]);  //and the cost of the cheapest segment that contains it.


        if (maxR < lr[i].second) maxR =lr[i].second, costR=INT_MAX;   //The largest integer in the shop
        if(lr[i].second==maxR) costR=min(costR,c[i]);  //and the cost of the cheapest segment that contains it.

        if (maxLen<lr[i].second - lr[i].first + 1) maxLen=lr[i].second - lr[i].first + 1, costLen=INT_MAX;  //The length of the longest segment
        if(lr[i].second-lr[i].first+1==maxLen) costLen=min(costLen,c[i]);       //and the cost of the cheapest of such segments.

        
        int ans = costL + costR;    //all integers between minL and maxR will get included
        if(maxLen==maxR - minL + 1)  //except when both maxR and minL lie in one single segment we won't have to add cost of two different segments. then we just need to check which is optimal(minimum cost), i.e whther adding cost of two segments including minL and maxR or cost of single segment including both.
            ans=min(ans, costLen);

        cout <<ans<<endl;
    }
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
