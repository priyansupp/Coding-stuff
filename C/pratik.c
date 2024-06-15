#include<stdio.h>
#include<stdlib.h>
int main()
{
    int star=0, minus=0,r, c;
    char x;

    FILE * fpointer = fopen("ML4-input.txt", "r");
    fscanf(fpointer, "%d %d", &r, &c);
//    printf("%d %d", r, c);
//    fscanf(fpointer, "%c", x);
    char arr[r+1][c+1];
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            fscanf(fpointer, "%c", &x);
            arr[i][j] = x;
        }
    }
 //   for(int i=0; i<r; i++)
 //   {
   //     for(int j=0; j<c; j++)
     //   {
     //       printf("%c", arr[i][j]);
// }
//       printf("\n");
//}
//    while(row<r && column<c)
//    {
//        s=0;
//        while(s<=c)
//        {
//    for(k=0; a[row][k]==*; k++)
//    {
//        star++;
//        else if(a[k]== -)
//        {
//            break;
//        }
//    }
//    printf("%d", star);
//    for(l=0; a[row][l]==-; l++)
//    {
//        minus++;
//        else if(a[l]== *)
//        {
//            break;
//        }
//    }
//    printf("%d", minus);
//        s=s+k+l;
//    }
//    row++;
//    column= k+l;
//    }
}
