#include<stdio.h>
int main()
{
    long long int n,m,a,t;
    scanf("%lld %lld %lld", &n, &m, &a);
    if(n%a!=0 && m%a!=0){
         t=(n/a+1)*(m/a+1);
    }
    else if(n%a==0 && m%a!=0){
         t=(n/a)*(m/a+1);
    }
        else if(n%a!=0 && m%a==0){
         t=(n/a+1)*(m/a);
    }
    else{
         t=(n/a)*(m/a);
    }
   printf("%lld\n", t);
}
