#include<stdio.h>
typedef struct{
    int r;
    int c;
    char ele;
}matrix;
int main()
{
    FILE *fp;
    int row,column,i,j,k=0;
    fp=fopen("week15-ML2-input.txt", "r");
    fscanf(fp,"%d%d",&row,&column);
    matrix *mat = (matrix*)malloc((row*column)*sizeof(matrix));
    int diag=row+column-1;
    int **elements=(int**)malloc((diag*30)*sizeof(int*));
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            fscanf(fp,"%d%d%c", &mat[k].r, &mat[k].c, &mat[k].ele);
            k++;
        }
    }
}
