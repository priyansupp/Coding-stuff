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
#define ft              first
#define sd              second
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


ll miniarraysum(int ind, vector<int> &a, vector<int> &b, vector<int> &dp){
    if(ind == 0){
        ll noswap = 0;
        for(int i = 0; i < a.size() - 1; i++){
            for(int j = i + 1; j < a.size(); j++){
                noswap += (a[i] + a[j]) * (a[i] + a[j]);
                noswap += (b[i] + b[j]) * (b[i] + b[j]);
            }
        }
        swap(a[0], b[0]);
        ll swapped = 0;
        for(int i = 0; i < a.size() - 1; i++){
            for(int j = i + 1; j < a.size(); j++){
                swapped += (a[i] + a[j]) * (a[i] + a[j]);
                swapped += (b[i] + b[j]) * (b[i] + b[j]);
            }
        }
        swap(a[0], b[0]);
        return min(noswap, swapped);
    }
    if(dp[ind] != -1) return dp[ind];
 
    ll noswap = miniarraysum(ind - 1, a, b, dp);
    swap(a[ind], b[ind]);
    ll swapped = miniarraysum(ind - 1, a, b, dp);
    swap(a[ind], b[ind]);

    return dp[ind] = min(noswap, swapped);
}


ll minisum(vector<int> &a, vector<int> &b){
    int n = a.size();
    vector<int>dp(n, -1);
    return miniarraysum(n - 1, a, b, dp);
}


// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    forr(i, n) cin >> a[i];
    forr(i, n) cin >> b[i];
    cout << minisum(a ,b) << '\n';
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
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
