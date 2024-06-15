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



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll>x(n);
        forr(i,n) cin>>x[i];
        sort(x);
        vector<ll>neg,pos;
        forr(i,n){
            if(x[i]<0) neg.pb(-1*x[i]);
            else pos.pb(x[i]);
        }
        int negs=neg.size();
        int poss=pos.size();
        ll length=0;
        sort(neg);
        sort(pos);
        if(!neg.empty() && !pos.empty()){
            int l=poss-1;  // start from last index not first else WA when spots will be repeated.
            while(l>=0){
                length+=2*pos[l];
                l-=k;   // while taking a bag of k, all the k-1 spots behind it will also get covered
            }
            int i=negs-1;
            while(i>=0){
                length+=2*neg[i];
                i-=k;
            }       
            // add all the distance and subtract the greatest distance among the two.
            length-=max(neg[negs-1],pos[poss-1]);
        }
        else if(neg.empty()){
            int l=poss-1;
            while(l>=0){
                length+=2*pos[l];
                l-=k;
            }
            length-=pos[poss-1];
        }
        else if(pos.empty()){
            int l=negs-1;
            while(l>=0){
                length+=2*neg[l];
                l-=k;
            }
            length-=neg[negs-1];
        }

        cout<<length<<endl;
    }

    return 0;
}
