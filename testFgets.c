#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 100

int main() {
	FILE *fp;
	char s[N+1];
	
	if((fp=fopen("hello.txt","rt"))==NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
    	exit(1);
	}
	
    	while(fgets(s,N,fp) != NULL) {     //读取字符串 
    		printf("%s",s);
	}
	
	fclose(fp);
	system("pause");
	return 0;
}
