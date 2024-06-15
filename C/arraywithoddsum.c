#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, s=0, flag=0,x;
        scanf("%d", &n);
        //int a[n];
        for(int i=0; i<n; i++){
            scanf("%d", &x);
            s+=x;
            if(x%2 !=0)
                flag++;
        }
        printf((s%2 || (flag>0 && flag<n))?"YES\n":"NO\n");

    }
}
