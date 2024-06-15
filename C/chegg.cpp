#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;      //taking input of n
    vector<float>a(n);      // declaring array of n numbers using vector STL 
    for(int i=0;i<n;i++){
        cin>>a[i];          //taking input of a1,a2...an
    }
    vector<float>aa(3*n);   //declaring 3 times the inital size vector
    for(int i=0;i<n;i++){   //initializing all the values in 3*n vector.
        aa[i]=a[i];
        aa[i+n]=a[i];
        aa[i+2*n]=a[i];
    }
    
    for(int i=0;i<n;i++){
        float maxcool=0;
        int c=0;
        for(int j=i;j<i+2*n;j++){
            maxcool=max(aa[j], maxcool);
            if(aa[j]<maxcool/2){
                cout<<j-i<<" ";
                c=1;
                break;
            }
        }
        if(c==0){
            cout<<-1<<" ";
        }
    }
    return 0;
}