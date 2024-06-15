#include<stdio.h>
#include<stdlib.h>

int Small(char);
int Capital(char);
int Digit(char);

int main(){
	int x=0,y=0,z=0;
	char c;
	do{
		scanf("%c",&c);
		x+=Small(c);
		y+=Capital(c);
		z+=Digit(c);


	}while(c!='$');
	printf("Number of capital letters: %d\n”,y);
printf("Number of small letters: %d\n”,x);
printf("Number of digits: %d\n”,z);
	return 0;
}

int Small(char c){
	if((int)c>=97&&(int)c<=122){
		return 1;
	}else{
		return 0;
	}

}

int Capital(char c){
	if((int)c>=65&&(int)c<=90){
		return 1;
	}else{
		return 0;
	}

}

int Digit(char c){
	if((int)c>=48&&(int)c<=57){
		return 1;
	}else{
		return 0;
	}

}
