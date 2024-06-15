#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define forr(i,n) for(ll i=0;i<n;i++)
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define srtpairbysec(v) sort(v.begin(),v.end(),sortbysec)
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
const ll MOD=1e9+7;
ll __=1;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);          //return (a.second > b.second);  for sorting in decreasing order by second element.
}

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negative result, so gotta add b.
        ret += b;
    return ret;
}

// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    forr(i,n) cin>>a[i];
    ll ans = 0;

    // If the position of MSB of two numbers is equal then  ai & aj>ai⊕aj always, else never.
    // find all numbers with position at 0th, 1st, 2nd , 3rd... bits

    for(int j = 0; j <= 29; j++){    //stored in int hence carry j upto atleast 30 bits(starting from 0th bit).
        ll cnt = 0;
        for(int i = 0; i < n; i++){   //check for every number at that bit
            if(a[i] >= (1<<j) && a[i] < (1<<(j+1))){    // i.e the highesst bit of number lies at jth bit
                cnt++;                                  //counting total number of numbers with msb at jth bit.
            }
        }
        ans += cnt*(cnt-1)/2;                           //nCr.... choosing any two numbers out of total cnt will give a valid pair.
    }
    cout<<ans<<"\n";

}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
