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
    vector<int>a(n);
    forr(i,n) cin>>a[i];
    int c=0,j=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            j=i;
            while(a[j+1]<a[j] && j<n-1){
                c++;
                j++;
            }
            break;
        }
    }
    // cout<<j-c<<"**"<<j<<endl;
    reverse(a.begin()+j-c,a.begin()+j+1);
    forr(i,n-1){
        if(a[i]>a[i+1]){
            cout<<"no";
            return;
        }
    }
    cout<<"yes"<<endl;
    cout<<j-c+1<<" "<<j+1;

}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
