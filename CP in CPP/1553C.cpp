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
#define deb(x)          cout << #x << ": " << x << '\n'
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
    string s;
    cin>>s;
    int onewin = 0, twowin = 0;
    double mini;
    int c = 0;
    forr(i,10){    //change all first's ? to 1
        if(i%2 == 0){
            if(s[i] != '0') onewin++;
        }
        else{
            if(s[i] == '1') twowin++;
        }
        if(onewin > twowin + ceil((10.0 - (i+1))/2)){
            mini = i + 1;
            c = 1;
            break;
        }
    }
    if(c == 0){
        mini = 10;    //when onewin is never greater than twowin in first iteration.. i.e it means it takes till end to decide the result
    }

    onewin = 0;
    twowin = 0;

    forr(i,10){    //change all second's ? to 1
        if(i%2 == 0){
            if(s[i] == '1') onewin++;
        }
        else{
            if(s[i] != '0') {
                twowin++;
            }
        }
        if(twowin > onewin  + (10-(i+1))/2){
            mini = min(mini, (double)(i + 1));
            break;
        }
    }
    cout<< mini <<'\n';
}




int main()
{
    cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
