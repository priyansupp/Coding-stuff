#include<bits/stdc++.h>
using namespace std;

int n;

vector<long double>x,v;

bool good(long double t){
    long double x1 = -1e9;
    long double x2 = 1e9; 
    for(int i = 0; i  < n; i ++){
        x1 = max(x1, x[i] - t*v[i]);
        x2 = min(x2, x[i] + t*v[i]);
        if(x1 >= x2) return false;
    }
    return true;
}


int main()
{
    cin>>n;
    x.resize(n); v.resize(n);
    for(int k = 0; k < n; k ++){
        cin>>x[k]>>v[k];
    }
    

    long double l = 0;   // bad
    long double r = 1e9;  // good
    for(int i = 0; i < 55; i++){
        long double t = (l+r)/2;
        if(good(t)){
            r = t;
        }
        else{
            l = t;
        }
    }

    cout<<setprecision(20)<<r<<'\n';

}