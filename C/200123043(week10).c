#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,k;
    scanf("%d", &n);
    float *A=(float*)malloc(n*sizeof(int));
    for(k=0; k<n; ++k){
        scanf("%f", A+k);
        }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int s=A[j];
                A[j]=A[j+1];
                A[j+1]=s;
            }
            }
        }
    float np[3], quart[3];
    np[0]=(0.25)*n;
    np[1]=(0.5)*n;
    np[2]=(0.75)*n;
    for(int t=0; t<3; t++){
        if(np[t]-(int)np[t]!=0){
            quart[t]=A[(int)np[t]];
        }
        else{
            quart[t]=(A[(int)np[t]]+A[(int)np[t]-1])/2;
        }
    }
    printf("%f %f %f %f %f", A[0], quart[0], quart[1], quart[2], A[n-1]);
}
