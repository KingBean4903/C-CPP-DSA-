#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>

union semun
{
	int val;
	struct semid-ds *buf;
	unsigned short *array;
};

void semaphore_op(int semid, int op)
{
	
	struct sembuf operation;
	operation.sem_num = 0;
	operation.sem_op = op;
	operation.sem_flg = 0;

	if (semop (semid, &operation, 1) == -1)
	{
		perrror("semop");
		exit (EXIT_FAILURE);
	}
}

int main(void) 
{
	
	key_t key;
	int semid;
	union semun sem_union;

	key = ftok("semfile", 75);

	semid = semget (key, 1, 0666 | IPC_CREAT);
	if (semid == -1)
	{
		perror("semget");
		exit (EXIT_FAILURE);
	}

	sem_union.val = 1;
	if (semctl (semid, 0, SETVAL, sem_union) == -1)
	{
		perror("semctl");
		exit (EXIT_FAILURE);
	}

	// Fork the process
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		// Child process
		printf("Childl Waiting to enter critical section...\n");
		semaphore_op(semid, -1);
		printf("Child: Entered critical section.\n");
		sleep(2);
		printf("Child: Leaving critical section.\n");
		semaphore_op (semid, 1);
		exit(EXIT_SUCCESS);
	}  else { 
		
		printf("Parent: Waiting to enter critical section....\n");
		semphore_op (semid, -1);
		printf("Parent: Entered critical section.\n");
		sleep(2);
		printf("Parent: Leaving critical section.\n");
		semaphore_op (semid, 1);

		wait (NULL);
	
		if (semctl (semid, 0, IPC_RMID, sem_union) == -1)
		{
				perror ("semctl");
				exit(EXIT_FAILURE);
		}
			printf("Semaphore removed.\n");
	}
	return 0;
}
