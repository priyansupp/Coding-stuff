#include <iostream>
#include <cmath>
#include <utility>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <deque>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <bitset>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsort(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())


ll query(ll x){
    cout<<"? "<<x<<endl;
    ll y;
    cin>>y;
    return y;
}

inline void solve(){
    ll x1=1e18;
    ll y1=query(x1);
    ll x2=x1-y1-1;
    ll y2=query(x2);
    cout<<"! "<<y2+1<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
