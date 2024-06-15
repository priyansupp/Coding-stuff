#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k;
class stack{    // each stack class will have three substacks to maintain everything about the stack class
                // smain keeps the element 
                // smin keeps the minimum element until then
                // smax keeps the maximum element until then
                // for the half segment [3,2,5,4]: smain = [3,2,5,4], smin = [3,2,2,2], smax = [3,3,5,5]
    public:
    vector<ll> smain, smin = {LLONG_MAX}, smax = {LLONG_MIN};
    void push(ll x){       // only used with s2
        smain.push_back(x);
        smin.push_back(min(smin.back(), x));
        smax.push_back(max(smax.back(), x));
    }
    ll pop(){             // only used with s1, unless s1 is empty then we've to pop all elements from s2 and push them into s1 then pop from s1.
        ll res = smain.back();
        smin.pop_back();
        smax.pop_back();
        smain.pop_back();
        return res;
    }
    bool empty(){
        return smain.empty();
    }
    ll mini(){
        return smin.back();    // last element in smin substack
    }
    ll maxi(){
        return smax.back();    // last element in smax substack
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

bool good(){     // checks if max[l...r] - min[l...r] <= k
    ll miniele = min(s1.mini(), s2.mini());
    ll maxele = max(s1.maxi(), s2.maxi());
    return maxele - miniele <= k;
}


int main()
{
    ll n;
    cin >> n >> k;
    vector<ll>a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];

    int l = 0;
    ll res = 0;
    for(int r = 0; r < n; r++){
        add(a[r]);               // while inserting we'll have to keep check of newmax, newmin(which is easy to check)    
        while(!good()){
            remove();        // while removing, we'll have to keep check of what newmax, newmin becomes now in the remaining segment.(this is hard to do as we'll have to keep track the second minimum/maximum element also and then third also(for next removal)). thus at every point we'll have to keep track of newmax, newmin and store it in form of stack, whenever an element is removed we can pop from the top of minstack and maxstack and we'll get our newmin, newmax.
            l++;
        }
        res += r - l + 1;     // if max - min <= k then every segment in between will also hold this property.
    }
    cout << res << '\n';
    return 0;

}

