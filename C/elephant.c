#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d", &x);
    y=x/5;
    if(y*5== x){
        printf("%d", y);
    }
    else{
        printf("%d", y+1);
    }
}
