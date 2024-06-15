#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *ptr;
    int sno;
    int roll;
    char name[100];
    char id[6];
    char cname[100];
}
student;
int main()
{
    int f; 
    scanf(" %d", &f);
    char chr;    
    scanf(" %c", &chr);
    char* t = malloc(sizeof(char) * 20);
    scanf(" %[^\n]s", t);

    int *x = malloc(sizeof(int) * 10);
    int sizetaken = 0;

    for(int j = 0; j < 20; j++)
    {
        if(t[j] == '\0' ) break;
        if(t[j] == ' ') continue;
        x[sizetaken++] = t[j] - 48;
    }
    free(t);
    int bool[] = {0,0,0,0,0};
    for(int b = 0; b < sizetaken; b++)
    {
        if(x[b] == 1)
            bool[0]++;
        else if(x[b] == 2)
            bool[1]++;
        else if(x[b] == 3)
            bool[2]++;
        else if(x[b] == 4)
            bool[3]++;
        else if(x[b] == 5)
            bool[4]++;
    }
    student info;
    info.ptr = malloc(200 * sizeof(char));
    for(int i = 0; i < f; i++)
    {
        scanf("\n%[^\n]s", info.ptr);
        char *t= strtok(info.ptr, &chr);

        for(int check = 0; check< 5; check++)
        {
            if(bool[check] != 0)
            {
                switch(check)
                {
                    case 0: info.sno = atoi(t);   break;
                    case 1: info.roll = atoi(t);     break;
                    case 2: strcpy(info.name , t);   break;
                    case 3: strcpy(info.id , t);     break;
                    case 4: strcpy(info.cname , t);  break;
                }
            }
            t= strtok(NULL, &chr);
        }

        for(int check = 4; check > -1; check--)
        {
            if(bool[check] != 0)
            {
                switch(check)
                {
                    case 0: printf("%d,",info.sno);  break;
                    case 1: printf("%d",info.roll);    break;
                    case 2: printf("%s,",info.name);    break;
                    case 3: printf("%s,",info.id);      break;
                    case 4: printf("%s,",info.cname);    break;
                }
            }
        }
        printf("\n");
    }

    free(info.ptr);
    free(x);
    return 0;
}
