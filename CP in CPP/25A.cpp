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
#define revsrt(v)      sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()



int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    forr(i,n) cin>>v[i];
    int o=0,e=0;
    forr(i,3){
        if(v[i]%2==0) e++;
        else o++;
    }
    if(o>e){
        forr(i,n){
            if(v[i]%2==0){
                cout<<i+1;
                break;
            }
        }
    }
    else{
        forr(i,n){
            if(v[i]%2!=0){
                cout<<i+1;
                break;
            }
        }
    }
    return 0;
}
