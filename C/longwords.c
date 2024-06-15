#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
            int i;
        char word[100];
        scanf("%s", word);
        for(i=0; word[i]!='\0'; i++){
            continue;
        }
        if(i>10){
        printf("%c%d%c\n", word[0], i-2, word[i-1]);
        }
        else{
            printf("%s\n", word);
        }
}
}
