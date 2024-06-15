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
#define revsrt(v)       sort(v.rbegin(),v.rend())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define acc(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define input()         int n; cin>>n; vector<int>a(n); forr(i,n) cin>>a[i]


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

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negative result, so gotta add b.
        ret += b;
    return ret;
}

const ll MOD=1e9+7;
ll __=1;

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n, k;
    cin >> n >> k;
    if(n == 4 && k == 3){
        cout << -1 << '\n';
        return;
    }
    vector<int>a(n/2), b(n/2);

    // Try to find a pairing such that sum(a[i]&b[i])=0.... a[i]&a[i]' = 0

    for(int i = 0;i < n/2; i++){
        a[i] = i;
        b[i] = n - (i + 1);
    }
    debug(a);
    debug(b);
    if(k != n - 1){          // try to find for other values of just by swapping a few values from the pairs
        for(int i = 0; i < n/2; i++){
            if(a[i] == k){
                swap(a[0], a[i]);
                break;
            }else if(b[i] == k){
                swap(a[0], b[i]);
                break;
            }
        }
    }else{          // in special cases when k == n - 1
        swap(a[0], b[1]);
        debug(a); debug(b);
        swap(a[2], a[3]);
        debug(a); debug(b);
    }
    // debug(a);
    // debug(b);
    for(int i = 0; i < n/2; i++){
        cout << a[i] << " " << b[i] << '\n';
    }
    // int sum = 0;
    // forr(i,n/2) sum += a[i]&b[i];
    // cout << sum << "$$$" << '\n';

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
