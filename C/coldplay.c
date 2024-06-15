#include<stdio.h>
int main()
{
    int t,m,s;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &s);
        printf("%d \n", (m-m%s)/s);
    }
}
