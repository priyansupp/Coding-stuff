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
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsort(v)      sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....



int main()
{
    int n;
    cin>>n;
    vector<int>res;
    for(int i=1;i<=n;i++){
        if(n%i==0) res.pb(i);
    }
    int c=0,d=0;
    forr(i,res.size()){
        string s=to_string(res[i]);
        forr(j,s.length()){
            if(s[j]!='4' && s[j]!='7'){
                c=1;
                break;
            }
        }
        if(c==0){
            d=1;
            break;
        }
        else c=0;
    }
    if(d==1) cout<<"YES";
    else cout<<"NO";

    return 0;
}
