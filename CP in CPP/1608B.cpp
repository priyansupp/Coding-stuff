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
        int n,a,b;
        cin>>n>>a>>b;
        
        if(a+b>n-2 || abs(a-b)>1) cout<<-1<<endl;
        else{
            vector<int>res;
            int l=1,r=n;
            if(a*b!=0){
            if(a==b){
                while(a--){
                    res.pb(l);
                    l++;
                    res.pb(r);
                    r--;
                    res.pb(l);
                    l++;
                }
                int h=res[3*b-1];
                for(int i=3*b;i<n;i++){
                    res.pb(++h);
                }
            }
            else if(a>b){
                int p=a;
                while(a--){
                    res.pb(l);
                    l++;
                    res.pb(r);
                    r--;
                }
                int h=res[2*p-1];
                for(int i=2*p;i<n;i++){
                    res.pb(--h);
                }
            }
            else{
                int p=b;
                while(b--){
                    res.pb(r);
                    r--;
                    res.pb(l);
                    l++;
                }
                int h=res[2*p-1];
                for(int i=2*p;i<n;i++){
                    res.pb(++h);
                }
            }
            }
            else if(a==0 && b!=0){
                forr(i,n) res.pb(i+1);
                swap(res[0],res[1]);
            }
            else if(b==0 && a!=0){
                forr(i,n) res.pb(i+1);
                swap(res[n-1],res[n-2]);
            }
            else if(a==0 && b==0){
                forr(i,n) res.pb(i+1);
            }
            forr(i,n) cout<<res[i]<<" ";
            cout<<endl;
        }
    }

    return 0;
}
