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
#define revsort(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        forr(i,n) cin>>a[i];
        int k=maxV(a);
        if(a[0]==k || a[n-1]==k){
            if(k==a[n-1]){
                cout<<k<<" ";
                for(int i=n-2;i>=0;i--) cout<<a[i]<<" ";
            }
            else{
                cout<<k<<" ";
                for(int i=n-1;i>=1;i--) cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
