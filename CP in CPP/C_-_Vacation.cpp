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

int points(vector<vector<int>> &tasks, int i, int prev, vector<vector<int>> &dp){
    if(i < 0){
        return 0;
    }
    if(dp[i][prev] != -1) return dp[i][prev];
    int ans = 0;
    for(int k = 0; k <= 2; k++){
        if(prev == k) continue;
        ans = max(ans, tasks[i][k] + points(tasks, i - 1, k, dp));
    }

    return dp[i][prev] = ans;

}


// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    int n;
    cin >> n;
    vector<vector<int>>tasks(n, vector<int>(3));
    forr(i, 0, n) cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
    vector<vector<int>>dp(n, vector<int>(4, -1));
    cout << points(tasks, n - 1, 3, dp);
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
