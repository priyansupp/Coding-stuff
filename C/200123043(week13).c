#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Students{
    int Sno;
    int roll;
    char name[100];
    char ID[6];
    char course[100];
};
int rollcall(int roll){
    int c=0;
    for(int i=1;i<9;i++){
    if(((roll/10000)%10)==0 && ((roll/1000)%10)==i){
        c=i;
    }
    }
    for(int i=1;i<4;i++){
    if(((roll/10000)%10)==2 && ((roll/1000)%10)==i){
        c=i+8;
    }
    }
    if(((roll/100000)%10)==2 && ((roll/10000)%10)==0 && ((roll/1000)%10)==5){
        c=12;
    }
}
    int comp(char s[6]){
    int count=0;
    if(s[0]=='H') count=1;
    if(count==1 && s[1]=='S') count=1;
    else count=0;
    if(count==1 && s[2]=='4') count=1;
    else count=0;
    if(count==1 && s[3]=='2') count=1;
    else count=0;
    if(count==1 && s[4]=='4') count=1;
    else count=0;
    return count;
}
int main(void)
{
    int n,c,number;
    scanf("%d", &n);
    struct Students **S;
    struct Students stud;
                S= (struct Students**)malloc(11*sizeof(struct Students*));
            for(int i=0;i<11;i++){
                    S[i]=(struct Students *)malloc(20*sizeof(struct Students));
                for(int j=0;j<20;j++){
                    S[j][i].Sno=0;
                    S[j][i].roll=0;
                    strcpy(S[j][i].name,"\b");
                    strcpy(S[j][i].ID,"\b");
                    strcpy(S[j][i].course,"\b");
                }
            }
             for(int i=0;i<n;i++){
        scanf("%d",&stud.Sno);
        scanf("%d",&stud.roll);

        scanf("%[^,]%*c", stud.name);
        scanf("%[^,]%*c", stud.ID);
        scanf("%[^\n]%*c", stud.course);
        int c[11]={0,0,0,0,0,0,0,0,0,0,0};
        if(comp(stud.ID)){
            int rollcheck=rollcall(stud.roll);
            for(int i=0;i<11;i++){
            if(rollcheck==i+1){
                *(*(S+i)+c[i])=stud;
                c[i]++;
            }
            }
             }
        }
        for(int i=0;i<11;i++){
        for(int j=0;j<20;j++){
            printf("%d %d %s %s %s\n",S[i][j].Sno,S[i][j].roll,S[i][j].name,S[i][j].ID,S[i][j].course);
        }
        printf("\n");
    }
    return 0;
}
