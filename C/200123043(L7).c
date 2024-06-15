#include<stdio.h>
#include<stdlib.h>
float exp(float x, int k)
{
    float prod=1;
    for(int i=1; i<=k;i++)
    {
        prod*=x;
    }
    return prod;
}
int fact(int n)
{
    int factorial=1,f;
    for(f=1; f<=n; f++)
    {
        factorial*=f;
    }
    return factorial;
}
float sinef(float x, int n)
{
    float sinesum=0;
    int j=1,k=1;
    for(int i=1; i<=(2*n-1); i+=2)
    {
        j++;
        sinesum+=exp(-1.0,j)*exp(x,k)/(fact(i));
        k+=2;
    }
    return sinesum;
}
int main()
{
    while(1)
    {
        float x;
        int n;
        scanf("%f %d", &x, &n);
        if(x==0 && n ==0)
        {
            printf("End");
            break;
        }
        else
        {
            printf("%.5f", sinef(x,n));
        }
    }
        return 0;
}
