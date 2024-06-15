#include<stdio.h>
int main()
{
    double x,y,z;
    scanf("%f", &x);
    y=x/5;
    z=ceil(y);
    if(y-z == 0){
        printf("%f", y);
    }
    else{
        printf("%f", z);
    }
}
