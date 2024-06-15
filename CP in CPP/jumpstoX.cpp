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
        int n;
        cin>>n;
        int k=1,sum=0,neg;
        while(sum<n){    // jump until sum reaches on or beyond n.
            sum+=k;
            k++;        //k increases when the loop runs last time but is not added in the sum.
        }
        if((sum-n)%2==0) cout<<k-1<<endl;       // total (k-1) jumps to reach sum.

        else if((sum+k-n)%2==0) cout<<k<<endl;  // if (sum-n)%2==1 then we take one more jump to the right and check
        //if now (newpos-n)%2==0 [yes, print no. of jumps, else take one more jump and that'd surely result (newwpos-n)%2==0].
        //there are total k jumps now, one more added from previous i.e (k-1)+1
        
        else cout<<k+1<<endl;                   //when (newwpos-n)%2==0
    }
    return 0;
}
