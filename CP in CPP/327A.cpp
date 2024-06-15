#include <bits/stdc++.h>

using namespace std;
using std::string;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007



//--------------SOLVE---------------//
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    forr(i,n) cin>>a[i];
    int i=0;
    int onestart=0;
    forr(i,n) if(a[i]==1) onestart++;   //counting initial ones.
    
    if(onestart==n){   //cases of all 1's but we have to perform 1 flip operation necessarily
        cout<<n-1;
        return;
    }

    int onegain=0;
    int maxone=0,actualgain=0;
    for(int i=0;i<n;i++){   //brute force method for each subarray(as n is small)
        onegain=0;
        maxone=0;
        for(int j=i;j<n;j++){
            if(a[j]==0){   //will be converted into 1
                onegain++;
            }
            else{
                onegain--;
            }
            if(onegain<0){
                onegain=0;
            }
            maxone=max(maxone,onegain);   // maximum 1's that can be obtained after flip starting from j=i to some index j<n
        }
        actualgain=max(maxone,actualgain);  // maximum of all maximums is the actual 1's gained.
            
    }
    cout<<onestart+actualgain;
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
