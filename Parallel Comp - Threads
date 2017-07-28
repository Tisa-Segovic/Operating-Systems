#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/* Global variables, accessible to any thread */
int a = 1, b = 3, c = 4, d = 2, e = 8, f = 7;
int r1, r2, r3;
pthread_t thread1, thread2, thread3;

void *function_2( void *ptr ){
	r2 = (a + b);
	pthread_join( thread2, NULL);
	r2 = r1 * r2;
	pthread_exit(NULL);
}

void *function_3( void *ptr ){
	r1 = (c - d);
	pthread_exit(NULL);
}

int main(){ 
	int  iret1, iret2, iret3;

	iret1 = pthread_create( &thread1, NULL, function_2, NULL);
	iret2 = pthread_create( &thread2, NULL, function_3, NULL);

	r3 = (e + f);
	pthread_join( thread1, NULL);
	printf("%d\n",(r2+r3));

	exit(EXIT_SUCCESS);
}
