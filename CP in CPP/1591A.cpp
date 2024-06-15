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
        int h=1,c=0;
        forr(i,n){
            if(a[i]==0){
                if(i>=1 && a[i-1]==0){
                    c=1;
                }
            }
            else if(a[i]==1){
                if(i>=1 && a[i-1]==0) h++;
                else if(i>=1 && a[i-1]==1) h+=5;
                else if(i==0) h++;
            }
            if(c==1) break;
        }
        if(c==1) cout<<-1<<endl;
        else cout<<h<<endl;
    }

    return 0;
}
