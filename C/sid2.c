#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* chr;
}character;
int main()
{
    character A;
    int *n;
    A.chr = (char*)malloc(200*sizeof(char));
    n = (int*)malloc(10*sizeof(int));
    int t,row;
    scanf("%d", &row);
    for(int i=0;i<10;i++)
    {
        scanf("%d", &n[i]);
    }

    for(int i=0;i<row;i++)
    {
        scanf("%*[\n]%[^\n]", A.chr);
        for(int j=0;j<strlen(A.chr);j++)
        {
            for(t=0;t<10;t++)
            {
                if((j+1)==n[t])
                {
                    break;
                }
            }
            if((j+1)!=n[t])
                printf("%c", A.chr[j]);
        }
        printf("\n");
    }
}
