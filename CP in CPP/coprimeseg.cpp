#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class stack{    // each stack class will have three substacks to maintain everything about the stack class
                // smain keeps the element 
                // gcd keeps the gcd of all the elements until that position
    public:
    vector<ll> smain, gcd;
    void push(ll x){
        smain.push_back(x);
        if(gcd.empty()) gcd.push_back(x);
        else gcd.push_back(__gcd(gcd.back(), x));
    }
    ll pop(){
        ll res = smain.back();
        gcd.pop_back();
        smain.pop_back();
        return res;
    }
    bool empty(){
        return smain.empty();
    }

} s1, s2;    // creating 2 stack classes for maintaining the whole segment(s1 maintains the left half of the segment, s2 maintains right half)


void add(ll x){
    s2.push(x);
}

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good(){     
    return __gcd(s1.gcd.back(), s2.gcd.back()) == 1;
}


int main()
{
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];

    ll l = 0;
    ll minilen = INT_MAX;
    for(ll r = 0; r < n; r++){
        add(a[r]);               // while inserting we'll have to keep check of gcd    
        while(1){
            if(!good()){
                break;
            }
            remove();        // while removing, we'll have to keep check of what gcd becomes now in the remaining segment.
            l++;
        }
        add(a[--l]);
        if(good()) minilen = min(minilen, r - l + 1);
    }
    if(minilen == INT_MAX) cout << -1;
    else cout << minilen << '\n';
    return 0;

}

