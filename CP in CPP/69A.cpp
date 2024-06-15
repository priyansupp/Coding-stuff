#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,fx=0,fy=0,fz=0;
    cin>>n;
    int x,y,z;
    while(n--){
        cin>>x>>y>>z;
        fx+=x;
        fy+=y;
        fz+=z;
    }
    if(fx==0 && fy==0 && fz==0) cout<<"YES";
    else cout<<"NO";
}
