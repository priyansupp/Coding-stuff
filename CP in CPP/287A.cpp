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
#define srt(v)          sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007



//--------------SOLVE---------------//
void solve(){
    char mat[4][4];
    forr(i,4){
        forr(j,4){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j]==mat[i+1][j+1]){
                if(mat[i][j+1]==mat[i][j] || mat[i+1][j]==mat[i][j]){
                    cout<<"YES";
                    return;
                }
            }
            else if(mat[i+1][j]==mat[i][j+1]){
                if(mat[i][j]==mat[i+1][j] || mat[i+1][j+1]==mat[i+1][j]){
                    cout<<"YES";
                    return;
                }
            }
        }
    }
    cout<<"NO";
    
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
