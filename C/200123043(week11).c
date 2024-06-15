#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *A[2][3];
    A[0][0]=(char*)calloc(10, sizeof(char));
    A[0][1]=(char*)calloc(10, sizeof(char));
    A[0][2]=(char*)calloc(10, sizeof(char));
    A[1][0]=(char*)calloc(20, sizeof(char));
    A[1][1]=(char*)calloc(20, sizeof(char));
    A[1][2]=(char*)calloc(20, sizeof(char));
    int t=90;
    for(int i=0; i<2; i++){
        printf("\nOriginal array:\n");
        for(int j=0;j<3; j++){
            for(int k=0;k<10*(i+1);k++){
            A[i][j][k]=(char)t;
            printf("%c", A[i][j][k]);
            t--;
             if(t==64){
                t=90;
            }
            }
            printf("\n");
        }
        printf("\n");
        if(i==0){
        char r[11], rr[11], rrr[11];
    printf("The three copied arrays are\n");
    memcpy(r, A[0][0], 10*sizeof(char));
    printf("%s\n", r);
    memcpy(rr, A[0][1], 10*sizeof(char));
    printf("%s\n", rr);
    memcpy(rrr, A[0][2], 10*sizeof(char));
    printf("%s\n", rrr);
        }
        if(i==1){
        char row[21], roww[21], rowww[21];
    printf("The three copied arrays are\n");
    memcpy(row, A[1][0], 20*sizeof(char));
    printf("%s\n", row);
    memcpy(roww, A[1][1], 20*sizeof(char));
    printf("%s\n", roww);
    memcpy(rowww, A[1][2], 20*sizeof(char));
    printf("%s\n", rowww);
        }
    }
    free(A[0][0]);
    free(A[0][1]);
    free(A[0][2]);
    free(A[1][0]);
    free(A[1][1]);
    free(A[1][2]);
    return 0;
}
