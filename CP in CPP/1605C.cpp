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

int difff(string& s,int n){
    forr(i,n){
        if(s[i]=='a'){
            return i;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<pair<int,int>>v;
        int diff=difff(s,n);
        
        forr(i,n){
            if(s[i]=='a'){
                diff=i-diff;
            }
            if(diff>3){
                diff=i;
                continue;
            }
            else{
                v.pb({diff,i});
                diff=i;
            }
        }
        if(v.empty()) cout<<-1<<endl;
        else{
            int mini=INT_MAX;
            for(int i=0;i<v.size();i++){
                mini=min(mini,abs(v[i].second-v[i].first));
            }
            cout<<mini+1<<endl;
        }
    }

    return 0;
}
