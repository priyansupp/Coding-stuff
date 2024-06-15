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
    ll a,s;
    cin>>a>>s;
    stack<int>res;
    string aa=to_string(a);
    string ss=to_string(s);
    int j,i;
    for(j=ss.length()-1, i=aa.length()-1;j>=0 && i>=0;i--){
        if(aa[i]>ss[j]){
            int r=(ss[j]-'0')+(ss[j-1]-'0')*10;
            int c=aa[i]-'0';
            if(r-c>9 || r-c<0){
                cout<<-1<<endl;
                return;
            }
            res.push(r-c);
            j-=2;
        }
        else{
            int n1=ss[j]-'0', n2=aa[i]-'0';
            int k=n1-n2;
            res.push(k);
            j--;
        }
    }
    if(i>=0 && j<0){
        cout<<-1<<endl;
        return;
    }
    if(j>=0){
        while(j>=0){
            res.push(ss[j]-'0');
            j--;
        }
    }

    while(res.top()==0) res.pop();
    while(!res.empty()){
        cout<<res.top();
        res.pop();
    }
    cout<<endl;
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
