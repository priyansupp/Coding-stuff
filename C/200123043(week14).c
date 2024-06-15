#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char *ch;
    int Sno;
    int roll;
    char name[100], id[6], cname[100];
} student;
int main(void)
{
    int *ptr, num,i;
    *ptr=(int*)malloc(10*sizeof(int));
    char del, field[5],fieldnum[5];
    scanf("%d %c", &num, &del);
    for(int j=0;j<5;j++){
        scanf("%c", &field[j]);
        if(field[j]=='1'){
                break;
        }
        fieldnum[j]=atoi(field[j]);
    }
    student info[num];
    for (i=0;i<num;i++){
        info[i].ch=(char*)malloc(200*sizeof(char));
        scanf("\n%s[^\n]s", info[i].ch);
    }
    for(i=0;i<num;i++){
            char out[20]={' '};
            int j=0,k=0;
            while(info[i].ch[k]!=del){
                    out[j]=info[i].ch[k];
                    j++;
                    k++;
               }
               info[i].Sno=atoi(out);
               k++;
               j=0;
               while(info[i].ch[k]!=del){
                    out[j]=info[i].ch[k];
                    j++;
                    k++;
               }
               info[i].roll=atoi(out);
               k++;
               j=0;
               while(info[i].ch[k]!=del){
                    out[j]=info[i].ch[k];
                    j++;
                    k++;
               }
               strcpy(info[i].name[100],out);
               k++;
               j=0;
               while(info[i].ch[k]!=del){
                    out[j]=info[i].ch[k];
                    j++;
                    k++;
               }
               strcpy(info[i].id[6],out);
               k++;
               j=0;
               while(info[i].ch[k]!=del){
                    out[j]=info[i].ch[k];
                    j++;
                    k++;
               }
               strcpy(info[i].cname[100],out);
    }
    for(int i=0;i<num;i++){
    for(int a=fieldnum[4];a>=0;a--){
    switch(a)
    {
                    case 0: printf("%d,",info[i].Sno);  break;
                    case 1: printf("%d",info[i].roll);    break;
                    case 2: printf("%s,",info[i].name);    break;
                    case 3: printf("%s,",info[i].id);      break;
                    case 4: printf("%s,",info[i].cname);    break;
                }
    }
}
}
