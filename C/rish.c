#include<stdio.h>
#include<math.h>
int fibon_iterative(int a){
    int f1=0,f2=1,f;
    int count=1;
    for(int i=2;i<a;i++){
        f=f1+f2;
        f1=f2;
        f2=f;
        printf("count variable= %d\n",count);
        count++;
    }
    return f;
}
int fibon_recursive(int a){
    int count=1;
    if(a<=1)
        return a;
    else {
        printf("\t %d", count);
        count++;
        return fibon_recursive(a-1)+fibon_recursive(a-2);
    }
}
int main()
{
    int n;
    printf("Enter the value of n to get nth Fibonacci number ");
    scanf("%d", &n);
    printf("nth Fibonacci number using iterative function = %d\n", fibon_iterative(n));
    printf("\nnth Fibonacci number using recursive function = %d", fibon_recursive(n));
}
