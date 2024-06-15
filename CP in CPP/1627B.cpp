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
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define srtpairbysec(v) sort(v.begin(),v.end(),sortbysec)
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define deb(x)          cout << #x << " : " << x << '\n'
#define input()         int n; cin>>n; vector<int>a(n); forr(i,n) cin>>a[i]
const ll MOD=1e9+7;
ll __=1;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);          //return (a.second > b.second);  for sorting in decreasing order by second element.
}

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negative result, so gotta add b.
        ret += b;
    return ret;
}

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    for(int i = 0; i < n; i++){    // Rahul will eventually sit on all the positions so it doesn't matters we can start from starting corner to end and then sort the answer as rahul's distance will keep increasing with increase in k(initially he'll sit in middle then towards the edges and distance will increase). But we can just reverse engineer and make him.
        for(int j = 0;j < m;j++){
            int dist = 0;         // The optimal seat for Tina is always one of the corner seats.
            dist = max(dist, abs(i-0)+abs(j-0));
            dist = max(dist, abs(i-0)+abs(j-(m-1)));
            dist = max(dist, abs(i-(n-1))+abs(j-0));
            dist = max(dist, abs(i-(n-1))+abs(j-(m-1)));
            v.push_back(dist);
        }
    }
    sort(v.begin(), v.end());
    for(int k = 0; k < n*m; k++){
        cout<<v[k]<<" ";
    }
    cout<<'\n';
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
