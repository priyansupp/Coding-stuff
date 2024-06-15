#include<stdio.h>
void main()
{
    short int a,b;                /*declaring various data types*/
    int c,f;
    char d,e,g,h;
    scanf("%hd %hd %d %c %c %d", &a, &b, &c, &d, &e, &f);       /*scanning variables*/
    g=a;
    h=b;
    switch(g)               /*using switch*/
    {
        case('A'):          /*nested case in switch statement*/
            switch(h)
            {
                case('N'): printf("Andaman & Nicobar Islands");
                break;
                case('P'): printf("Andhra Pradesh");
                break;
                case('R'): printf("Arunachal Pradesh");
                break;
                case('S'): printf("Assam");
                break;
            }
            break;
        case('M'):
            switch(h)
            {
                case('P'): printf("Madhya Pradesh");
                break;
                case('H'): printf("Maharastra");
                break;
                case('N'): printf("Manipur");
                break;
                case('L'): printf("Meghalaya");
                break;
                case('Z'): printf("Mizoram");
                break;
            }
            break;
         case('N'):
            switch(h)
            {
                case('L'): printf("Nagaland");
                break;
            }
            break;
        case('T'):
            switch(h)
            {
                case('N'): printf("Tamil Nadu");
                break;
                case('S'): printf("Telangan");
                break;
                case('R'): printf("Tripura");
                break;
            }
            break;
    }
}
