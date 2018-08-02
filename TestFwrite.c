#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct people {
	int age;
	char name[30];
};


int main(){
	FILE *fp;
	people pe[2];
	pe[0].age=25;strcpy(pe[0].name,"wang");
	pe[1].age=28;strcpy(pe[1].name,"liu");
	int i;
	
	if((fp=fopen("hello.txt","w")) == NULL) {
		exit(1);
	}
	printf("open success!");
	
	for(i=0;i<2;i++) {
		fwrite(&pe[i],sizeof(struct people),1,fp);       //写入结构体 
	}
	
	fclose(fp);
	return 0;
}
