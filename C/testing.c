#include<stdio.h>
int main()
{
    int  b[3][4];
    b[2][1]=21;
    const char *p[] = {"google", "microsoft", "yahoo"};
printf("%s, %c, %c\n", p[0], p[1][2], *(p[2]+3));
//    printf("%p\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &b[2][1],*(&b[2][1]),*(*(b+2)+1),*(*(&b[0]+2)+1), *(*(&b[2])+1), *(*(&b[1]+1)+1), *((&b[2][0])+1),*(b[2]+1));
//    printf("%p, %p, %p, \n", &z[0], &z[1], &z[2]);
//        printf("%p, %p, %p, \n", z[0], z[1], z[2]);
//        printf("%p, %p \n", &z[1]+1, &z[0]+2);
//        printf("%p, %p \n", z[2]+1, &z[2][1]);
//        printf("%p, %p %p\n" ,z[1], &z[1], &z[0]+1);
//        printf("%p, %p, %p \n", z, z+1, z+2);
//        printf("%p, %p, %p \n", &z, &z+1, &z+2);
//prints identical values; z is interpreted a
//    printf("%p\n", &a);
//    printf("%p\n", a);
//    printf("%p", &p);
}
