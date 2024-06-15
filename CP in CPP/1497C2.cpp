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
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int u=n-k+3;
        forr(i,k-3) cout<<1<<" ";
        if(u%2!=0){
            cout<<u/2<<" "<<u/2<<" "<<1<<endl;
        }
        else{
            if((u/2)%2!=0){
                cout<<2<<" "<<u/2-1<<" "<<u/2-1<<endl;
            }
            else{
                cout<<u/2<<" "<<u/4<<" "<<u/4<<endl;
            }
            
        }
    }

    return 0;
}
