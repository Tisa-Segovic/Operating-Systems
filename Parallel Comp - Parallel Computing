#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define KEY 2020

int main(){
	int a = 1, b = 3, c = 4, d = 2, e = 8, f = 7;

	// Parent process creates a shared memory
	int id = shmget(KEY, 4 * sizeof(float),IPC_CREAT | 0600);

	float* space = (float*) shmat(id, NULL, 0);

	if (fork() == 0) {
		// Process 1 - (a + b); forks into a child process and becomes a parent process
		if (fork() == 0) {
			// Process 2 - (c - d); forks and is itself a child process
			space[1] = (c - d);
			exit(0);
		}
		space[0] = (a + b);
		wait(NULL);

		space[3] = space[0] * space[1];
		exit(0); // Totally done with it as well
	}
	else (fr == 0){
		// Process 3 - (e + f); this is now a forked parent process
		space[2] = (e + f);
		wait(NULL);

		printf("%f \n", space[3]+space[2]);
	}
}
