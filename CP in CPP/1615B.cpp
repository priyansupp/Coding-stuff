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
#define revsrt(v)       sort(all(v))
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


ll __=1;
// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int l, r;
    cin >> l >> r;
    vector<bitset<20>>A;
    for(int i = l; i <= r; i++){
        A.pb(i);
    }
    vector<int>zero(20, 0);
    for(int j = l; j <= r; j++){
        if(A[j - l][0] == 0) zero[0]++;
        if(A[j - l][1] == 0) zero[1]++;
        if(A[j - l][2] == 0) zero[2]++;
        if(A[j - l][3] == 0) zero[3]++;
        if(A[j - l][4] == 0) zero[4]++;
        if(A[j - l][5] == 0) zero[5]++;
        if(A[j - l][6] == 0) zero[6]++;
        if(A[j - l][7] == 0) zero[7]++;
        if(A[j - l][8] == 0) zero[8]++;
        if(A[j - l][9] == 0) zero[9]++;
        if(A[j - l][10] == 0) zero[10]++;
        if(A[j - l][11] == 0) zero[11]++;
        if(A[j - l][12] == 0) zero[12]++;
        if(A[j - l][13] == 0) zero[13]++;
        if(A[j - l][14] == 0) zero[14]++;
        if(A[j - l][15] == 0) zero[15]++;
        if(A[j - l][16] == 0) zero[16]++;
        if(A[j - l][17] == 0) zero[17]++;
        if(A[j - l][18] == 0) zero[18]++;
        if(A[j - l][19] == 0) zero[19]++;
    }
    cout << minV(zero) << '\n';
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

    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
