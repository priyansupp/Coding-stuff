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


ld fact(int n)
{
    ld res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}


// remember to always typecast functions like pow to avoid hacking
//--------------SOLVE--------------//
void solve(){
    string Dl, Dn;
    cin>>Dl>>Dn;
    int des = 0, res = 0;
    forr(i, Dl.length()){
        if(Dl[i] == '+') des++;
        else des--;
    }
    int q = 0;
    forr(i, Dn.length()){
        if(Dn[i] == '+') res++;
        else if(Dn[i] == '-') res--;
        else q++;
    }
    cout.precision(10);     //You can set the precision directly on std::cout and use the std::fixed format specifier. 
    //Precision upto 10 decimal digits here.

    // std::cout << std::setprecision (15) << 3.14159265358979 << std::endl; also works

    int diff = abs(des - res);
    if(q>=diff && (q-diff)%2 == 0){
        int y = (q - diff)/2;
        int x = diff + y;
        cout<< fixed <<  fact(x+y)/(fact(x)*fact(y)*(1 << q));  //using fixed format specifier with cout.precision().
    }
    else cout<<0;
}




int main()
{
    // cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
