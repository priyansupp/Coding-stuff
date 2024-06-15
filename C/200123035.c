#include<stdio.h>
typedef struct{
    int r;
    int c;
    char img_value;
}matrix;
int main()
{
    FILE *fp;
    int row,column,i,j,k=0;
    fp=fopen("week15-ML2-input.txt", "r");
    fscanf(fp,"%d%d",&row,&column);
    char image[row][column];
    matrix *mat = (matrix*)malloc((row*column)*sizeof(matrix));
    int diag=row+column-1;
    int **elements=(int**)malloc((diag*30)*sizeof(int*));
    for(int t=0;t<diag;t++){
        elements[t]=(int*)malloc(30*sizeof(int));
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            fscanf(fp,"%d%*c%d%*c%c", &mat[k].r, &mat[k].c, &image[i][j]);
            k++;
        }
    }
    int a=0,b=0;
    for(i=0;i<=column;i++){
            int y=i, z=0;
        for(j=1;j<i+1;j++){
            if(image[y][z]=='*' && a==0){
                if(b!=0){
                    printf("%d ",b);
                    b=0;
                }
                a=1;
            }
            else if(image[y][z]=='*' && a!=0)
                a++;
            else if(image[y][z]=='-' && b==0){
                if(a!=0){
                    printf("%d ",a);
                    a=0;
                }
                b++;
            }
            else if(image[y][z]=='-' && b!=0)
                b++;
                y--;
                z++;
        }
    if(a!=0)
        printf("%d ",a);
    if(b!=0)
        printf("%d ",b);
    a=b=0;
    printf("\n");
    }
    a=b=0;
    for(i=1;i<row;i++){
        int z=i;
        int y=row-1;
        for(j=1;j<=row-i;j++){
            if(image[y][z]=='*' && a==0){
                if(b!=0){
                    printf("%d ", b);
                    b=0;
                    }
                    a=1;
            }
            else if(image[y][z]=='*' && a!=0)
                a++;
            else if(image[y][z]=='-' && b==0){
                if(a!=0){
                    printf("%d ",a);
                    a=0;
                }
                b++;
            }
            else if(image[y][z]=='-' && b!=0)
                b++;
            y--;
            z++;
            }
            if(a!=0)
                printf("%d ", a);
            if(b!=0)
                printf("%d ", b);
            a=b=0;
            printf("\n");
        }
        free(mat);
        free(elements);
}
