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
#define pb push_back
#define ft              first
#define sd              second
#define forr(i,n)       for(ll i=0;i<n;i++)
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
        int n;
        cin>>n;
        vector<int>arr(n);
        forr(i,n) cin>>arr[i];
        if(find(arr.begin(),arr.end(),0)==arr.end()){
             forr(i,n) cout<<arr[i]<<" ";
             cout<<'\n';
        }
        else{
            map<int,int>mp;
            forr(i,n){           //how to store unique elements with its count in a map from an array.
                 if(mp.find(arr[i])==mp.end()){
                     mp.insert({arr[i],1});
                 }
                 else mp[arr[i]]++;
            }
            for(auto it:mp){
                cout<<it.first<<" ";
            }
            for(auto it:mp){
                if(it.second>1){
                    it.second--;
                    while(it.second--) cout<<it.first<<" ";
                }
            }
            cout<<'\n';
        }
        
    }

    return 0;
}
