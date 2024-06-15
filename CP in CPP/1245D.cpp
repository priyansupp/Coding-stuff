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

const int N = 1e6;
int Parent[N];
int Size[N];

void make(int v){
    Parent[v] = v;
    Size[v] = 1;
}

int find(int v){
    if(v == Parent[v]) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        Parent[b] = a;
        Size[a] += Size[b];
    }
}


// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> city(n + 1);
    // create an extra node 0, which has connections with all the cities and with edge weights c[i] for connection wtih city i. Now node 0 along with all other nodes form a graph. Find the MST of this graph.
    // Connection of node i with node 0(in MST) means i has power station (installed at the cost of c[i]).
    // Connection of node j with node i(int MST), (i != j != 0) means i and j are connected through wires.
    forr(i, 1, n + 1) cin >> city[i].first >> city[i].second;

    vector<int>c(n + 1), k(n + 1);

    forr(i, 1, n + 1) cin >> c[i];
    forr(i, 1, n + 1) cin >> k[i];

    vector<pair<ll, pair<int, int>>>edges;

    forr(i, 1, n + 1){
        edges.push_back({c[i], {0, i}});
    }

    forr(i, 1, n + 1){
        forr(j, i + 1, n + 1){
            int dist = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
            ll cost = (ll)dist * (k[i] + k[j]);
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    forr(i, 0, n + 1) make(i);

    ll total_cost = 0;
    vector<int>power_stations;
    vector<pair<int, int>>connections;

    for(auto edge : edges){
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        total_cost += w;
        Union(u, v);
        if(u == 0 || v == 0){           // if either is node 0, then the other has power station.
            power_stations.push_back(max(u, v));
        }else{
            connections.push_back({u, v});
        }
    }

    cout << total_cost << '\n';

    cout << power_stations.size() << '\n';
    for(int ps : power_stations) cout << ps << " ";

    cout << '\n' << connections.size() << '\n';
    for(pair<int, int> c : connections) cout << c.first << " " << c.second << '\n';

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
