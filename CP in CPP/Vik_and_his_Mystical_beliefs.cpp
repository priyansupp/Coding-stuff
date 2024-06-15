#include <bits/stdc++.h>
using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;

const ll MOD = 1e9+7;
const ld PI = acos(-1.0);

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


//---------------------------------------DEBUGGING ZONE--------------------------------------------//
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


//----------------------------------------- FUNCTIONS-------------------------------------------------//
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}  //return (a.second > b.second);  for sorting in decreasing order by second element.
ll modulo(ll a, ll b = MOD){ return (a % b + b) % b;}       // a % b = a - b * (a / b);
int countSetBits(ll x){int Count=0;while(x>0){if(x&1) Count++;x=x>>1;}return Count;}

ll dfs(int i, int j, vector<vector<int>> &a, vector<vector<ll>> &dp, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return INT_MIN;
    }
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = 0;
    if(i < n - 1  && a[i][j] < a[i + 1][j]) ans = max(ans, 1 + dfs(i + 1, j, a, dp, n, m));
    if(i > 0 && a[i][j] < a[i - 1][j]) ans = max(ans, 1 + dfs(i - 1, j, a, dp, n, m));
    if(j < m - 1 && a[i][j] < a[i][j + 1]) ans = max(ans, 1 + dfs(i, j + 1, a, dp, n, m));
    if(j > 0 && a[i][j] < a[i][j - 1]) ans = max(ans, 1 + dfs(i, j - 1, a, dp, n, m));

    return dp[i][j] = ans;
}


// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << "helllo";
    vector<vector<ll>>dp(n, vector<ll>(m, -1));
    forr(i, 0, n){
        forr(j, 0, m){
            if(dp[i][j] == -1){
                ll ans = dfs(i, j, a, dp, n, m);
            }
        }
    }
    ll ans = 0;
    forr(i, 0, n){
        forr(j, 0, m){
            ans = max(ans, dp[i][j]);
        }
    }
    // cout << "hi";
    cout << ans << '\n';
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
    // cin >> __;
    while(__--){
        solve();
    }
    return 0;
}
