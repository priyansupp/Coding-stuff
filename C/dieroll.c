#include<stdio.h>
#include<math.h>
int main()
{
    int y,w,d,A,B,gcd,i=1;
    scanf("%d %d", &y,&w);
    if(y>w){d=7-y;}
    else{d=7-w;}
    while(i<=6)
    {
        if(6%i==0 && d%i==0)
        {
            gcd=i;
        }
        i++;
    }
    A= d/gcd;
    B= 6/gcd;
    printf("%d/%d", A, B);
}
