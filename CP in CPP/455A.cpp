#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    map<int, int>a;          // storing the element in sorted order along with its count.
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    ll dp[100001];
    dp[0] = 0;
    dp[1] = a[1];
    for(auto j = 2; j <= 1e5 + 1; j++){                   // calculating dp[j] for all the values of j(if it is not present in array, it won't add up in the net points as a[j] = 0).
        dp[j] = max(dp[j - 1], dp[j - 2] + (ll)a[j]*j);
    }
    auto it = a.rend();
    cout << dp[it->first] << '\n';     // of the last element (biggest element)

    return 0;
}