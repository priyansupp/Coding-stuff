#include<stdio.h>
int main()
{
     FILE *fp;
     int num,min=20;
     fp=fopen("week15-ML4-input.txt", "r");
     fscanf(fp, "%d", &num);
    int roll[num],marks[num][20];
    char lab[num][3];
     for(int r=0;r<num;r++){
                fscanf(fp,"%d %s", roll[r],lab[r]);
                 int t=0;
                 for(int j=0;j<20;j++){
        char d,c;
        fscanf(fp,"%d%c%c",marks[r][j],&d,&c);
        t++;
        if(c=='\n')
        break;
                }
                 for(int k=0;k<t;k++){                 //sorting
             int maximum=k;
             for(int j=k;j<t;j++){
             if(marks[r][j]>marks[r][maximum]){
            maximum=j;
        }
    }
    int tt=marks[r][k];
    marks[r][k]=marks[r][maximum];
    marks[r][maximum]=tt;
    }
    if(min>t){                                       //to find minimum labs
        min=t;
      }
}

for(int r=0;r<num;r++){
      printf("%d  ",roll[r]);
      printf("%s ",lab[r]);

      for(int j=0;j<min;j++){
        printf("%3d ",marks[r][j]);
      }
      printf("\n");
    }
    fclose(fp);
      return 0;
}
