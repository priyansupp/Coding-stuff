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
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
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
template<class T> void _print(unordered_set<T> mst){cerr << "[ "; for(T i : mst){ _print(i); cerr << ", ";} cerr << "]"; }
template<class T, class V> void _print(map<T, V> mp){cerr<<"[ ";for(auto i : mp){ _print(i); cerr << ", ";}cerr << "]"; }
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
    int n;
    cin >> n;
    vector<int>a(n);        // 2 2 3 4 0 1 2 0
    map<ll, ll>mp;          // {0 , 2}, {1, 1}, {2, 3}, {3, 1}, {4, 1}
    forr(i,n) 
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int>ans;
    int newj = 0;
    for(ll i = 0; i < n + 1;){     // mex can vary from 0,1,2,3,....,n for array with n elements.
        if(a.size() == 0) break;   // when array a is empty


        if(mp[i] == 0)            // is is nowhere found in the a, hence i becomes current mex.
        {
            set<ll>s;             // making set of all elements that appear in  vector a while traversing through it and breaking the very moment we find all elements in a < i (then all those elements will give MEX as i).
            // ll j = newj;
            ll j = 0;
            while(s.size() < i){     // for i=5, s will contain 0, 1, 2, 3, 4 and will the while loop will break the moment s.size() == 5 == i
                if(a[j] < i){        // set of only those elements whch are less than i and can potentially give mex  
                    s.insert(a[j]);
                }
                mp[a[j]]--;          // removing every elements count from map as those elements will be deleted from the array now.
                j++;
            }
            ans.push_back(i);    // pushing the mex
            
            // newj = j + 1;
            if(j == 0) a.erase(a.begin());    // removing elements from original array
            else a.erase(a.begin(), a.begin() + j);

            i = 0;         // we'll g=have to check again from 0, what comes mex now for the remaining array      

        }else{                   // that element is in the array a and hence cant be MEX
            i++;
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << " ";
    cout << '\n';

    

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
