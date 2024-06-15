#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N,B,J;
        cin>>N>>B;
        J=N;
        int A[N],i=0,tcost=0;
        while(J--){
            cin>>A[i];
            i++;
        }
        sort(A, A+N);
        for(i=0;i<N;i++){
            tcost+=A[i];
            if(tcost>B)
                break;
            if(tcost==B){
                i++;
                break;
            }
        }
        cout<<i;
    }
}
