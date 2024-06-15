#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>a;

bool good(double x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += floor(a[i]/x);        //summing total number of cuts that can be made with x as length of one cut.
    }
    return sum >= k;          //if such cuts can be made then true else false.
}


int main()
{
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    double l = 0;      //definitely good cut
    double r = 1e8;    //definitely bad cut(as no cut can be made of length 1e8 when max length of rope is 1e7).

    // maximum cut from 1e7 to 1e-6. We have to descend a total of like 1e15 orders.. i.e log2(1e15) = 50. 
    // So we can have a total of 100 iterations(for safe purposes) that will reduce the distance between l,r less than 1e-6.


    for(int i = 0; i < 100; i++){
        double m  = (l+r)/2;
        if(good(m)){
            l = m;
        }
        else{
            r = m;
        }
    }

    //floating point has 7 places of precision and double has 15 places of presision.
    // When outputting floating point numbers, cout has a default precision of 6 and it truncates anything after that(for both float and double).
    cout<<setprecision(20);      //increases the precision of cout and now the decimal representation will be correct to atleast 19 places and after that it'll truncate.
    cout<<l<<'\n';
    // cout<<r<<'\n'; works too as l,r are close enough to eachother (as we have ade 100 iterations).
    // or
    // cout<<setprecision(20)<<l<<'\n';


    // float f = 1.0/1024;
    // double d = 1.0/1024;
    // cout<<f<<'\n'<<d<<endl;
    return 0;
}