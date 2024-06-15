#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
const ll MOD = 1e9+7;
const ld PI = 3.1415926535897932384;

#define forr(i,n)       for(ll i=0;i<n;i++)
#define forr1(i,n)      for(ll i=1;i<n;i++)
#define pb              push_back
#define gcd             __gcd
#define all(v)          v.begin(),v.end()
#define rev(v)          reverse(all(v))
#define srt(v)          sort(all(v))
#define srtpairbysec(v) sort(all(v),sortbysec)
#define revsrt(v)       sort(all(v), greater<int>())
#define minV(v)         *min_element(all(v))
#define maxV(v)         *max_element(all(v))
#define fill(v,s)       iota(all(v),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define acc(v, initial) accumulate(all(v),initial)  //initial is the starting sum and then the vector values are added to it.
#define input(n, a)     int n; cin >> n; vector<int>a(n); forr(i, n) cin >> a[i]



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

ll minitime(int i, int k, int n, vector<int> &d, vector<int> &a, vector<vector<int>> &dp){
    if(i == 0){
        ll time = 0;
        int speed, prev = a[0];
        for(int ind = 1; ind < n; ind++){
            if(a[ind - 1] != 0) prev = a[ind - 1];
            speed = prev;
            time += (d[ind] - d[ind - 1]) * speed;
        }
        if(a[n - 1] != 0) prev = a[n - 1];
        speed = prev;
        time += (d[n] - d[n - 1]) * speed;
        return time;
    }
    if(dp[i][k] != -1) return dp[i][k];

    int x = a[i];

    int drop = INT_MAX;
    if(k > 0){
        a[i] = 0;
        drop = minitime(i - 1, k - 1, n, d, a, dp);
    }
    a[i] = x;
    int notdrop = minitime(i - 1, k, n, d, a, dp);

    return dp[i][k] = min(drop, notdrop);

}

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n, l, k;
    cin >> n >> l >> k;
    vector<int>d(n);
    vector<int>a(n);
    forr(i, n) cin >> d[i];
    d.pb(l);
    forr(i, n) cin >> a[i];
    vector<vector<int>>dp(n, vector<int>(k + 1, -1));
    cout << minitime(n - 1, k, n, d, a, dp);
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
    // cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
