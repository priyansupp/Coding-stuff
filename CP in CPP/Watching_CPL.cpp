#include <bits/stdc++.h>

using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;
const ll MOD = 1e9+7;
const ld PI = 3.1415926535897932384;

#define forr(i, a, n)   for(ll i = a; i < n; i++)
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define rev(v)          reverse(all(v))
#define srt(v)          sort(all(v))
#define srtpairbysec(v) sort(all(v),sortbysec)
#define revsrt(v)       sort(all(v), greater<int>())
#define minV(v)         *min_element(all(v))
#define maxV(v)         *max_element(all(v))
#define fill(v,s)       iota(all(v),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define acc(v, initial) accumulate(all(v),initial)  //initial is the starting sum and then the vector values are added to it.
#define input(n, a)     int n; cin >> n; vector<int>a(n); forr(i, 0, n) cin >> a[i]



//DEBUGGING ZONE//
#ifndef ONLINE_JUDGE
#define debug(x)        cerr << #x << " : "; _print(x); cerr << '\n'
#else
#define debug(x)         
#endif


template<class T>void _print(T t){cerr << t;}
template<class T, class V> void _print(pair <T, V> p){cerr<<"{"; _print(p.first);cerr <<", "; _print(p.second);cerr<<"}";}
template<class T> void _print(vector<T> v){cerr << "[ "; for(T i : v){ _print<T>(i); cerr << ", ";} cerr << "]"; }
template<class T> void _print(set<T> st){cerr << "[ "; for(T i : st){ _print(i); cerr << ", ";} cerr << "]"; }
template<class T> void _print(multiset<T> mst){cerr << "[ "; for(T i : mst){ _print(i); cerr << ", ";} cerr << "]"; }
template<class T> void _print(unordered_set<T> ust){cerr << "[ "; for(T i : ust){ _print(i); cerr << ", ";} cerr << "]"; }
template<class T, class V> void _print(map<T, V> mp){cerr<<"[ ";for(auto i : mp){ _print(i); cerr << ", ";}cerr << "]"; }
template<class T, class V> void _print(multimap<T, V> mmp){cerr<<"[ ";for(auto i : mmp){ _print(i); cerr << ", ";}cerr << "]"; }
template<class T, class V> void _print(unordered_map<T, V> ump){cerr<<"[ ";for(auto i : ump){ _print(i); cerr << ", ";}cerr << "]"; }


//DEBUGGING ZONE ENDS

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);  //return (a.second > b.second);  for sorting in decreasing order by second element.
}

ll modulo(ll a, ll b = MOD){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negative result, so gotta add b.
        ret += b;
    return ret;
}

int mintowers(int i, int sum1, int sum2, int k, vector<int> &h, vector<vector<vector<int>>> &dp){
    if(i == 0){
        if(sum1 >= k && sum2 >= k) return 0;
        if(sum1 >= k){
            if(sum2 + h[0] >= k) return 1;
        }
        if(sum2 >= k){
            if(sum1 + h[0] >= k) return 1;
        }
        return 1e8;
    }
    if(dp[i][sum1][sum2] != -1) return dp[i][sum1][sum2];

    int pick1 = 1e8, pick2 = 1e8, nopick = 1e8;
    if(sum1 < k) pick1 = 1 + mintowers(i - 1, sum1 + h[i], sum2, k, h, dp);
    if(sum2 < k) pick2 = 1 + mintowers(i - 1, sum1, sum2 + h[i], k, h, dp);
    nopick = 0 + mintowers(i - 1, sum1, sum2, k, h, dp);

    return dp[i][sum1][sum2] = min(pick1, min(pick2, nopick));
}

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int>h(n);
    forr(i, 0, n) cin >> h[i];
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2*k, vector<int>(2*k, -1)));
    cout << mintowers(n - 1, 0, 0, k, h, dp) << '\n';
    return;
}




int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);   //makes a file where all the dubug calls output their content
#endif

    // can use simple cin and cout to read and write to these specific files.
    // freopen("input.txt", "r", stdin);     
    // freopen("output.txt", "w", stdout);

    ll __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}
