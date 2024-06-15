#include<bits/stdc++.h>
using namespace std;

double c;

bool good(double x){
    return x*x + sqrt(x) >= c;
}


int main()
{
    cin>>c;
    double l = 0;
    double r =1e5;
    for(int i = 0; i < 100; i++){
        double m = (l+r)/2;
        if(good(m)){
            r = m;
        }
        else{
            l = m;
        }
    }

    cout<<setprecision(20)<<r<<'\n';

}