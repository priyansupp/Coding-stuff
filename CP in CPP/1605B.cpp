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
        string s;
        cin>>s;
        vector<int>v0,v1;
        int zero=0,one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') {
                v1.pb(i);
                one++;
            }
        }
        for(int j=n-1;j>=n-one;j--){
            if(s[j]=='0'){
                v0.pb(j);
                zero++;
            }
        }
        if(zero==0) cout<<0;     // 0 operations if already sorted
        else{
            cout<<1<<endl;       // atmost 1 operation.
            cout<<2*zero<<" ";   
        for(int k=0;k<zero;k++){
            cout<<v1[k]+1<<" ";
        }
        for(int u=v0.size()-1;u>=0;u--){
            cout<<v0[u]+1<<" ";              //just we have to replace the trailing zeros with one which will not have 
            //at proper place if the string was already sorted.... 0110110 we just have to replace the 0 at position 4 and 7 with 
            // 1 from position 2 and 3. because the rest of string is already at correct place.
        }
        }
        cout<<endl;

    }

    return 0;
}
