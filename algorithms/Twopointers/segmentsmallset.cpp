#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
vector<ll>a;

int cnt[100001];    // counter array to store number of a[i] == x in [l...r] i.e number of occurrence of each x(x is any element from the vector)
int num = 0;     // number of unique elements in [l....r]

void add(int x){                // addition(inclusion)
    cnt[x]++;
    if(cnt[x] == 1) num++;      // means x is newly added as its counter now is 1, hence it must be unique element(num++)
}

void remove(int x){             // subtraction(removal)
    cnt[x]--;
    if(cnt[x] == 0) num--;      // the element removed must be unique as its cnt[x] was only 1 and now 0.
}


bool good(){
    return num <= k;            // good segment if the condition is met.
}



int main()
{
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    
    int l = 0;
    ll res = 0;

    // for a particular good segment [l...r] having less than k unique elements, all the subsegments from [i....r] for all i from l,l+1,l+2,..,r would be a good segment as number of unique elements would keep decreeasing only.

    for(int r = 0; r < n ;r++){        // calculating good segments for a fixed r each time and appending to the res.
        add(a[r]);                     // addition(inclusion)
        while(!good()){                // everything in between is a good segment so we increase l to certain point until it gives good segment. // If everything outside the segment were a good segment then we would have increased l until it gives good segment and appended l to the result. 
            remove(a[l]);              // subtraction(removal)
            l++;
        }

        res += r - l + 1;
    }
    cout << res << '\n';

    return 0;
}