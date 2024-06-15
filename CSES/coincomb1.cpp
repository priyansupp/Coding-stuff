#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll modulo(ll x){
    int rem = x%MOD;
    if(rem < 0) return rem + MOD;
    else return rem;
}


int n, x;
vector<int>c;
vector<ll>dp(1000001, -1);
vector<vector<int>>ans;



// if we can take multiple coins of same denomination(elements can be duplicated and two sets with all same elements but different order will be different i.e [2, 3, 2, 2] and [3, 2, 2, 2] are different). DON'T DO SUCH QUESTIONS IN WHICH ORDER OF ELEMENTS IN FINAL ANSWER DOES MATTERS BY PICK/NOT-PICK METHOD.
ll coinsum(int sum){
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum];
    ll ways = 0;
    for(int i : c){
        if(sum - i >= 0) {
            ways += modulo(coinsum(sum - i));
        }
    }

    return dp[sum] = modulo(ways);
}


int main()
{
    cin >> n >> x;
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    cout << coinsum(x);
    return 0;
}