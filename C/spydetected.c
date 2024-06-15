#include<stdio.h>
int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        if(a[0]==a[1])
        {
            for(int i=0; i<n; i++)
        {
            if(a[i]!=a[0])
            {
                printf("%d \n", i+1);
                break;
            }
        }
        }
        else if(a[0]!=a[1])
        {
            if(a[0]==a[2]){
                printf("2 \n");
            }
            else{
                printf("1 \n");
            }

        }

    }
}
