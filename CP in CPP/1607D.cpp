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
        vector<int>arr(n);
        forr(i,n) cin>>arr[i];
        string s;
        cin>>s;
        int hehe=0;
        vector<int>vr,vb;
        forr(i,n){
            if(s[i]=='R'){
                vr.pb(arr[i]);
            }
            else vb.pb(arr[i]);
        }
        sort(vr);
        sort(vb);
        int maxx=1,maxxr=0;
        forr(i,vb.size()){
            if(arr[i]<1){
                hehe=1;
                cout<<"NO"<<endl;
                break;
            }
            else{
                if(arr[i]<=maxx){
                    maxx++;
                }
                if(maxx>i+1){
                    hehe=1;
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        forr(i,vr.size()){
            if(arr[i]>n){
                hehe=1;
                cout<<"NO"<<endl;
                break;
            }
            else{
                if(arr[i]>=i+1){
                    maxxr++;
                }
                if(maxxr>n-i+1){
                    hehe=1;
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(hehe==0) cout<<"YES"<<endl;

        
    }

    return 0;
}
