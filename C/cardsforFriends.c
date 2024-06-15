#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t!=0){
    t--;
    int w,h, i=1, x=2,n,j=1,a,b;
    scanf("%d %d %d", &w, &h, &n);
    while(w%x ==0)
    {
        i++;
        x=pow(2,i);
    }
    x=2;
    while(h%x ==0)
    {
        j++;
        x=pow(2,j);
    }
    a=pow(2,i-1);
    b=pow(2,j-1);
    if(a*b>=n){
        printf("YES\n");
    }else{
        printf("NO\n");
     }}
}
