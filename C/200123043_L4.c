#include<stdio.h>
int main()
{
    float x;           /*declaring floating variable*/
    char y,z;           /*declaring character variable*/
    scanf("%f %c %c", &x, &y, &z);      /*scanning input from the user*/
    switch(y)                           /*using switch statement to convert given into INR*/
    {
        case 'A': x=x*55.64;            /*declaring cases as per required*/
        break;
        case 'B': x=x*74;
        break;
        case 'C': x=x*3.42;
        break;
        case 'D': x=x*12.15;
        break;
        case 'E': x=x*4.72;
        break;
        case 'F': x=x*90.41;
        break;
        case 'H': x=x*0.2605;
        break;
    }
    switch(z)                       /*using switch statement to convert INR into required output*/
    {
        case 'A': x=x/55.64;
        break;
        case 'B': x=x/74;
        break;
        case 'C': x=x/3.42;
        break;
        case 'D': x=x/12.15;
        break;
        case 'E': x=x/4.72;
        break;
        case 'F': x=x/90.41;
        break;
        case 'H': x=x/0.2605;
        break;
    }
    printf("%f", x);
    return 0;
}
