#include<bits/stdc++.h>
using namespace std;


int m,n;
vector<int>t,z,y;

bool good(int x){
    int balloon = 0;
    for(int i = 0; i < n; i++){
        int a = x/(t[i]*z[i] + y[i]);
        int left = x - a*((t[i]*z[i] + y[i]));
        int j = 0;
        bool check = false;
        while(t[i]*j < left && j < z[i]){
            j++;
        }
        if(t[i]*j > left) j--;
        balloon += a*z[i] + j;
    }

    return balloon >= m;
}

int main(){

    cin>>m>>n;
    z.resize(n);
    y.resize(n);
    t.resize(n);
    for(int i = 0; i < n; i++){
        cin>>t[i]>>z[i]>>y[i];
    }
    int l = 0;  // no balloon in 0 mins
    int r = 1e9;  // definitely sufficient time to inflate all balloons in worst condition.

    while(r > l+1){
        int m = (l+r)/2;
        if(good(m)){
            r = m;
        }
        else{
            l = m;
        }
    }

    cout<< r <<'\n';
    for(int i = 0; i < n; i++){
        int a = r/(t[i]*z[i] + y[i]);
        int left = r - a*((t[i]*z[i] + y[i]));
        int j = 0;
        int balloonbyeach = 0;
        while(t[i]*j < left && j < z[i]){
            j++;
        }
        if(t[i]*j > left) j--;
        cout<<a*z[i] + j<<" ";
    }
    return 0;
}