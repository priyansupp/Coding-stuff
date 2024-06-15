#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())



int main()
{
    int n;
    cin >> n;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    // ---------
    for(int i = 2; i <= sqrt(n); i++){
        for(int j = i*i; j <= n; j += i){
            prime[j] = false;
        }
    }
    // ---------

    for(int i = 2; i <= n; i++){
        if(prime[i] == true) cout << i << " ";
    }

    return 0;
}
