#include<bits\stdc++.h>
using namespace std;

int sumofsquare(int m, int n){
    if(m==n) return n*n;
    else return m*m+sumofsquare(m+1,n);
}

int main()
{
    int m,n;
    cin>>m>>n;
    int t=sumofsquare(m,n);
    cout<<t;
    return 0;
}
