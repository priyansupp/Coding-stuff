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
    ll n;
    cin>>n;
    ll ans = 0;
    for(int i=0;i<60;i++){
        if(n & (1ll<<i)){
            ans += (1ll << (i+1)) - 1;
        }
    }


    //ANOTHER METHOD(just another idea from above approach). 0th bit changes n times and 1st bit changes floor(n/2) times...
    // ans = n;   
    // while(n){
    //     n /= 2;
    //     ans += n;
    // }

    cout<< ans << "\n";
}

// 0000
// 0001    1
// 0010    2
// 0011    1
// 0100    3
// 0101    1    
// 0110    2
// 0111    1
// 1000    4   for the number 8(= 2^3), see change in position of bits for a aparticular column all the way up. As a bit in a column toggles it increases the answer by 1. 0th bit changes 8 times(2^3), 1st bit changes 4 times(2^2), 3rd 2 times and 4th(MSB) changes only once when n becomes 8. therefore total = 8+4+2+1 = 2^4-1. Result for n=2^k is equal to 2^(k+1)−1
// 1001    1
// 1010    2
// 1011    1    
// 1100    3
// 1101    1  say for n=13, we'll have to calculate change in bits for every bit position and summing the result for each 2^bit for all the set bits...i.e sum(2^(bit+1)-1), where bit is the position of set bits.
// 1110    2
// 1111    1



int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
