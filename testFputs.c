#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 100

int main() {
	FILE *fp;
	char c[N] = "hello world,how are you,good bye!";
	
	if((fp=fopen("hello.txt","r+"))==NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
    exit(1);
	}
	
	fputs(c,fp); \\写入
	
	fclose(fp);
	system("pause");
	return 0;
}
