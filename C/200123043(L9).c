#include<stdlib.h>
int main()
{
    int t,m,n,o;
    scanf("%d", &t);
    int a[t];
    for(int i=0; i<t; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d %d %d", &m, &n, &o);
    while(o--){
            int mat[m][n];
            for(int i=0;i<m; i++){
                for(int j=0; j<n; j++){
                    mat[i][j]=a[t-1];
                    t--;
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
        printf("\n");
    }
}
