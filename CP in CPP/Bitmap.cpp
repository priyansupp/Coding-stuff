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

const int N = 1000;
int dist[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>>movements = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(vector<pair<int, int>> &source){
    queue<pair<int, int>>q;
    for(pair<int, int> u : source){
        q.push(u);
        int ux = u.first;
        int uy = u.second;
        dist[ux][uy] = 0;
        vis[ux][uy] = true;
    }

    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        int ux = u.first, uy = u.second;
        for(pair<int, int> move : movements){
            int vx = ux + move.first;
            int vy = uy + move.second;
            if(!isValid(vx, vy)) continue;
            if(!vis[vx][vy]){
                q.push({vx, vy});
                dist[vx][vy] = dist[ux][uy] + 1;
                vis[vx][vy] = true;
            }
        }
    }
    return;

}

// typecasting is important
//------------------------------------------SOLVE----------------------------------------------------//
void solve(){
    cin >> n >> m;
    vector<vector<char>>p(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> p[i][j];
        }
    }
    vector<pair<int, int>>source;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(p[i][j] == '1'){
                source.push_back({i, j});
            }
        }
    }
    bfs(source);
    forr(i, 0, n){
        forr(j, 0, m) cout << dist[i][j] << " ";
        cout << '\n';
    }

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
