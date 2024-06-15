#include<stdio.h>
int main()
{
    int t,k=0,l=0,ci,ri;
    int r[2],c[2];
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d", n);
        char a[n][n+1];
        k=0;
        l=0;
        for(int i=0; i<n; i++){
                for(int j=0; j<=n; j++){
                    scanf("%c", &a[i][j]);
                    if(a[i][j]=='*'){
                        r[k]=i;
                        c[l]=j;
                        k++;
                        l++;
                    }
                }
        }
        if(r[0]==r[1]){
            ci=c[1]-c[0];
                a[(r[0]+ci)][(c[0])]='*';
                a[(r[0]+ci)][(c[1])]='*';
        }
        if(c[0]==c[1]){
            ri=r[1]-r[0];
                a[(r[0])][(c[0]+ri)]='*';
                a[(r[1])][(c[0]+ri)]='*';
        }
        else{
            a[(r[0])][(c[1])]='*';
            a[(r[1])][(c[0])]='*';
        }
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    printf("%c", a[i][j]);
                }
        }
        printf("\n");

    }
}
