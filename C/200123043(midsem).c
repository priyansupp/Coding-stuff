#include<stdio.h>
#include<stdlib.h>
int main()
{
    int star, minus,r, c;
    char x;

    FILE * fpointer = fopen("ML4-input.txt", "r");
    fscanf(fpointer, "%d %d", &r, &c);
    char arr[r+1][c+1];
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            fscanf(fpointer, "%c", &x);
            arr[i][j] = x;
        }
    }
    int s, column=1,k;
    while(column<=c)
    {
        s=0;
        k=0;
        while(s<r)
        {
        star=0;
        minus=0;
    while(arr[k][column]=='*')
    {
        star++;
        k++;
        if(arr[k][column]== '-')
        {
            break;
        }

    }
    printf("%d ", star);
    while(arr[k][column]=='-')
    {
        minus++;
        k++;
        if(arr[k][column]== '*')
        {
            break;
        }

    }
    printf("%d ", minus);
        s=s+k;
    }
    column++;
    printf("-1 \n");
    }
}
