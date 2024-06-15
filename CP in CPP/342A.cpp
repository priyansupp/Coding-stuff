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
#define srtpairbysec(v) sort(v.begin(),v.end(),sortbysec)
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007
ll __=1;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

ll modulo(ll a, ll b){
    ll ret = a % b;    //simple modulus when a>=0
    if (ret < 0)       //when a<0.. Normally it gives negatuve result, so gotta add b.
        ret += b;
    return ret;
}

//--------------SOLVE---------------//
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int no=0,one=0,two=0,three=0,four=0,six=0;
    forr(i,n){
        cin>>a[i];
        if(a[i]==1) one++;
        else if(a[i]==2) two++;
        else if(a[i]==3) three++;
        else if(a[i]==4) four++;
        else if(a[i]==6) six++;
        else no=1;
    }

    //only groups of (1,2,4),(1,2,6) and (1,3,6) are possible.

    int g=n/3;
    if(no==1 || one!=g){
        cout<<-1;
        return;
    }
    int two_=two;
    two_-=four;
    if(two_<0 || two_+three!=six){
        cout<<-1;
        return;
    }
    if(four>0)
    while(four--){
        cout<<"1 2 4"<<endl;
        two--;
    }
    if(two>0)
    while(two--){
        cout<<"1 2 6"<<endl;
    }
    if(three>0)
    while(three--){
        cout<<"1 3 6"<<endl;
    }
}




int main()
{
    // cin>>__;
    while(__--){
        solve();
    }
    return 0;
}
