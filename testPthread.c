#include <stdio.h>
#include <pthread.h>

void thread1() {
	int i;
	for(i=0;i<6;i++) {
		printf("This is Thread1.\n");
		if(i==2) {
			pthread_exit(0);
		}
		sleep(1);
	}
}

void thread2() {
	int i;
	for(i=0;i<3;i++) {
		printf("This is Thread2.\n");
	}
	sleep(1);
	pthread_exit(0);
}

int main() {
	pthread_t id1,id2;
	int i,ret;
	pthread_attr_t attr;
  //初始化线程
	pthread_attr_init(&attr);
  //设置线程绑定属性
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
  //设置线程分离属性
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


	ret = pthread_create(&id1,&attr,(void *) thread1,NULL);
	if(ret!=0) {
		printf("Create pthread1 error!\n");
		exit(1);
	}


	ret = pthread_create(&id2,NULL,(void *) thread2,NULL);
	if(ret!=0) {
			printf("Create pthread2 error!\n");
			exit(1);
	}

	pthread_join(id2,NULL);
	return 0;
}
