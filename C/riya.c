#include<stdio.h>
#include<stdlib.h>

//int arr[2];      declaring in global variable,

int* arithmetic(int a, int b)
{
    int* arr=(int*)malloc(2*sizeof(int));    //declaring in heap section of the memory.
    int arr[2];
    arr[0]=a+b;
    arr[1]=a-b;
    return arr;
}


int main()
{
    int x,y;
    x=6;
    y=9;
    int* result=arithmetic(x,y);
    printf("%d %d",*result,*(result+1));
}

//text-->global variable-->main(){locals variables, all the function calls}-->stack-->heap
