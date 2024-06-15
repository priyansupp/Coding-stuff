// #include<stdio.h>
// #include<math.h>

// int main()
// {
//     float n;
//     scanf("%f", &n);
//     long long int i=(int)n;
//     int k;
//     long long int res=(n*pow(10,7)-i*pow(10,7)-1);
//     long long int r=res;
//     for(k=0;;k++){
//         r=r/10;
//         if(r*pow(10,k+1)!=res) break;
//     }
//     res=res/pow(10,k);

//     printf("Integer: %d, Float: %d", i,res);
// }


#include <stdio.h>
int add(int a, int b) {
    return (a+b);
}
int add1(int a, int b, int c) {
    return (a+b+c);
}
int add2(int a, int b, int c, int d, int e) {
    return (a+b+c+d+e);
}
int add3(int a, int b, int c, int d, int e, int f) {
    return (a+b+c+d+e+f);
}
int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    printf("%d+%d=%d\n",a,b,add(a,b));
    printf("%d+%d+%d=%d\n",a,b,c,add1(a,b,c));
    printf("%d+%d+%d+%d+%d=%d\n",a,b,c,d,e,add2(a,b,c,d,e));
    printf("%d+%d+%d+%d+%d+%d=%d\n",a,b,c,d,e,f,add3(a,b,c,d,e,f));

    return 0;
}