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
    int tt=n,c=0;
    int powtwo=0,powthree=0;
    while(tt>1){
        if(tt%3==0){
            tt/=3;
            powthree++;
        }
        else if(tt%2==0){
            tt/=2;
            powtwo++;
        }
        else{
            c=1;
            break;
        }
    }
    if(c==1 || powtwo>powthree){
        cout<<-1<<endl;
    }
    else{
        cout<<powthree+powthree-powtwo<<endl;
    }
}




int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
