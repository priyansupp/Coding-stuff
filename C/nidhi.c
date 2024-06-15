#include<stdio.h>
// #include<>
int main()
{
    char a[][];
    int star=0, minus=0,s,row=0, column=0;
    for(i=0; i<r; i++)
    {
        for(j=0;j<c; j++)
        {
            scanf("%c",&a[i][j]);
        }
    }
    while(row<r && column<c)
    {
        s=0;
        while(s<=c)
        {
    for(k=0; a[k][column]==*; k++)
    {
        star++;
        else if(a[k]== -)
        {
            break;
        }
    }
    printf("%d", star);
    for(l=0; a[l][column]==-; l++)
    {
        minus++;
        else if(a[l]== *)
        {
            break;
        }
    }
    printf("%d", minus);
        s=s+k+l;
    }
    row++;
    }
}
