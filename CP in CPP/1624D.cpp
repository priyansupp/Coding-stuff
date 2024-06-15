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
    if (ret < 0)       //when a<0.. Normally it gives negatuve result, so gotta add b.
        ret += b;
    return ret;
}



int palin(int n, int count, int k){
    if(n>=k){
        if(count<k){   //eg: in case when k=5, count=4... All k-1 strings will take the pair and the last one would remain with a single letter. therefore return 1
            return 1;
        }
        if(count == k){   //eg: in case when k=5, count=5... All k strings will take individual pairs of letters first then unpaired letters can be inserted in middle(will remain a palindrome).
            if(n < 2*count + k){    //unpaired letters won't reach till last kth string. So return 2(a pair of letter)
                return 2;
            }
            else{
                return 3;           //unpaired letters will reach till last kth string. So return 3(a pair of letter + a middle letter)
            }
        }
        else{
            return 2 + palin(n-2*k, count-k, k);    // in this case it is same as giving each k strings a pair of letters and again using the alogirthm for the rest of remaining letters(n-2*k) with number of pairs also decreasing by k.
        }
    }
    else return 0;         //possible when n-2*k<k
}

//--------------SOLVE--------------//
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    int count=0;
    for(int i=0;i<n-1;){
        if(s[i] == s[i+1]){
            i+=2;
            count++;    //total number of pairs of letters.
        }
        else i++;
    }
    
    cout<<palin(n, count, k)<<endl;


}




int main()
{
    cin>>__;
    while(__--){
        solve();
        // int n,k;
        // cin>>n>>k;
        // string s;
        // cin>>s;
        // unordered_map<char, int>pal;
        // for(auto a:s){
        //     pal[a]++;
        // }
        // ll even = 0;
        // ll odd = 0;
        // for(auto a: pal){
        //     even += a.second/2;
        //     odd += a.second%2;
        // }
        // ll ans = 2*(even/k);
        // odd += 2*(even%k);
        // if(odd >= k){
        //     ans++;
        // }
        // cout<<ans<<"\n";
    }
    return 0;
}
