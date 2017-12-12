#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <semaphore.h>

#define PERMS 0666
int my_result[6];
int counter = 0;
int a_and_b, c_and_d, e_and_f, r1, r2;
int a = 3, b = 2, c = 6, d = 1, e = 4, f = 5;
pthread_t thread1, thread2, thread3;
sem_t *p_sem1;
sem_t *p_sem2;

// T1
void *calc_2(void *ptr){
	int temp = ( a + b );
	my_result[counter] = temp;
	counter++;

	sem_post(p_sem1);
	sem_post(p_sem2);
	pthread_exit(NULL);
}

// T2
void *calc_3(void *ptr){
	int temp = ( c - d );
	my_result[counter] = temp;
	counter++; 

	sem_post(p_sem1);
	sem_post(p_sem2);
	pthread_exit(NULL);
}

// T3
void *calc_1(void *ptr){
	int temp = ( e + f );
	my_result[counter] = temp;

	sem_post(p_sem1);
	sem_post(p_sem2);
	pthread_exit(NULL);
}

// T4
int main(int argc, char *argv[]){
	p_sem1 = sem_open("my_semaphore1", O_CREAT, PERMS, 1);
	p_sem2 = sem_open("my_semaphore2", O_CREAT, PERMS, 0);

	int iret1 = pthread_create( &thread1, NULL, calc_2, NULL);
	int iret2 = pthread_create( &thread2, NULL, calc_3, NULL);
	int iret3 = pthread_create( &thread3, NULL, calc_1, NULL);

	sem_wait(p_sem2);
	sem_wait(p_sem2);
	r1 = ((my_result[0]) * my_result[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_wait(p_sem2);
	r2 = (r1 * (my_result[2]));
	pthread_join(thread3, NULL);

	// (3+2)*(6-1)*(4+5) = 225 
	printf("The final result is: %d \n", r2);
	return 0;
}
