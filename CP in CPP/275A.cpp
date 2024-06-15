#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][3],out[5][5];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) cin>>arr[i][j];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++) out[i][j]=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]%2!=0){
                    i+=1; j+=1;
                out[i-1][j]*=(-1);
                out[i][j-1]*=(-1);
                out[i][j]*=(-1);
                out[i][j+1]*=(-1);
                out[i+1][j]*=(-1);
                i--; j--;
            }
        }
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            if(out[i][j]==-1) out[i][j]=0;
            cout<<out[i][j];
        }
        cout<<endl;
    }
    return 0;
}

