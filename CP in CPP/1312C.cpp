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
#define input()         int n; cin>>n; vector<int>a(n); forr(i,n) cin>>a[i]
const ll MOD=(int)1e9+7;
ll __=1;

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
template<class T> void _print(unordered_set<T> mst){cerr << "[ "; for(T i : mst){ _print(i); cerr << ", ";} cerr << "]"; }
template<class T, class V> void _print(map<T, V> mp){cerr<<"[ ";for(auto i : mp){ _print(i); cerr << ", ";}cerr << "]"; }
template<class T, class V> void _print(unordered_map<T, V> ump){cerr<<"[ ";for(auto i : ump){ _print(i); cerr << ", ";}cerr << "]"; }

//DEBUGGING ZONE ENDS



bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);          //return (a.second > b.second);  for sorting in decreasing order by second element.
}

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negative result, so gotta add b.
        ret += b;
    return ret;
}

const ll cnst = (ll)1e16;

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    forr(i,n) cin>>a[i];

    // This is the solution that doesn't involve masks. Let's reverse the process and try to get all zeroes from the array a: since all ai≤10^16 we can start from maximum k^s≤10^16.

    // The key idea: since k^s> k^0 + k^1 + k^2 +... + k^(s-1) then there should be no more than one position pos such that a(pos)≥k^s and we should decrease it by k^s. Now we can decrease s by 1 and repeat the same process.

    // If at any step there are at least two a(pos)≥k^s or as result, we won't get array filled with 0 then there is no way to build the array a.

    // 1
    // 2 2
    // 9007199254740993 1

    int s;
    for(s = 1;;s++){
        if(pow(k,s)>cnst){
            break;
        }
    }
    debug(s);
    s--;
    while(s >= 0){
        int count = 0;
        int j;
        forr(i,n){
            if(a[i] >= pow(k,s)){
                count++;
                j=i;
            }
        }
        if(count > 1){
            cout<<"NO"<<'\n';
            return;
        }
        else if(count == 1){
            a[j] -= pow(k,s);
        }
        s--;
    }
    forr(i,n){
        if(a[i] != 0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
    return;

}




int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);   //makes a file where all the dubug calls output their content
#endif
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
