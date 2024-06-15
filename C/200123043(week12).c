#include<stdio.h>
#include<stdlib.h>
int ***reverse(int n,int *point){
    int row=point[n],column=point[n+1],matr=point[n+2];
    int c=1;
int ***newm=calloc(row,sizeof(int**));
for(int i=0;i<row;i++){
    newm[i]=calloc(column,sizeof(int*));
}
for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
        newm[i][j]=calloc(matr,sizeof(int));
    }
}
for(int i=0;i<matr;i++){
    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            newm[j][k][i]=point[n-c];
            c++;
        }
    }
}
return newm;
}
main(){
    int n;
    scanf("%d",&n);
    int *A=(int*)malloc((n+3)*sizeof(int));
    for(int i=0;i<=n+2;i++){
        scanf("%d",&A[i]);
    }
    int row=A[n],column=A[n+1],matr=A[n+2];
    int ***out=reverse(n,A);
    printf("\n output is \n");
    for(int i=0;i<matr;i++){
    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            printf("%d ",out[j][k][i]);
        }
        printf("\n");
    }
    printf("\n");
}
free(A);
}
