#include<bits/stdc++.h>
using namespace std;

bool pairss(long long arr[], long long size, int target)
{
    int i;
    int rem[target];
    for(i=0;i<target;i++){
        rem[i]=0;
    }
    for(i=0;i<size;i++){
        if(arr[i]<target){
            rem[arr[i]%target]++;
        }
    }
    for(i=1;i<target/2;i++){
        if(rem[i]>0 && rem[target-i]>0){
            return true;
        }
    }
    if(i>=target/2){
        if(target%2==0){
            if(rem[target/2]>1){
                return true;
            }
            return true;
        }
        else{
            if(rem[target/2]>0 && rem[target - target/2]>0){
                return true;
            }
            return true;
        }
    }
}

int main()
{
    long long A[9]={-3,-1,1,2,9,11,7,6,2};
    int t[8]={3,4,5,6,7,8,9,10};
    int temp=0;
    for(int i=0;i<8;i++){
        if(pairss(A,9,t[i])) temp++;
    }
    cout<<temp<<endl;
    return 0;
}