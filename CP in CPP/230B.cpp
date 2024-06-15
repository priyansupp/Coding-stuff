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


set<double> primes(){
    int n=1000000;
    bool isprime[n+1];
    forr(i,n+1) isprime[i]=true;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=i*i;j<n+1;j+=i){
            isprime[j]=false;
        }
    }
    set<double>res;
    forr(i,n+1){
        if(isprime[i]==true && i!=0 && i!=1){
            res.insert(i);
        }
    }
    return res;
}

//--------------SOLVE---------------//
void solve(){
    int n;
    cin>>n;
    vector<double>x(n);
    forr(i,n) cin>>x[i];
    //only squares of natural numbers are T-primes, i.e if a!=1 && a!=x[i] is a factor of x[i] then x[i]/a must also be another factor of x[i]. But the only factor x[i] has is 1,a,x[i] hence x[i]/a=a. a^2=x[i], x[i] is square of a natural number (particularly prime natural numbers only).
    set<double>res=primes();
    forr(i,n){
        double hehe=sqrt(x[i]);
        if(res.find(hehe)==res.end()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
}




int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
