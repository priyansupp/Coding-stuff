#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    ll p;
    cin >> n >> p;
    vector<int>a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll songs = 0;
    while(p >= sum){
        p -= sum;
        songs += n; 
    }
    vector<int>b(2*n);
    for(int i = 0; i < 2*n ; i++){
        b[i] = a[i%n];
    }
    
    // s >= p    minimize r - l + 1
    int l = 0, mini = INT_MAX;
    ll s = 0;
    int startsong;
    for(int r = 0; r < 2*n; r++){
        s += b[r];
        while(s - b[l] >= p){
            s -= b[l];
            l++;
        }
        if(s >= p) {
            mini = min(mini, r - l + 1);
            if(mini == r - l + 1) startsong = (l-1)%n;
        }
    }

    cout << startsong << " " << mini + songs << '\n';

    


    return 0;
} // namespace std;
