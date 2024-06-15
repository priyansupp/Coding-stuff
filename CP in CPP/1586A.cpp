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


bool is_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>odd;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0) odd.pb(i);
            sum+=a[i];
        }
        if(!(is_prime(sum))){
            cout<<n<<endl;
            forr(i,n) cout<<i+1<<" ";
            cout<<endl;
        }
        else{
            cout<<n-1<<endl;
            int j;
            for(j=0;j<odd.size();j++){
                if(!is_prime(sum-a[odd[j]])) break;
            }
            forr(i,n){
                if(i!=odd[j]) cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
