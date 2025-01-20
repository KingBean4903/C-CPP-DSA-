#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(void) 
{ 
	key_t key = ftok ("shmfile", 65);
	int shmid = shmget (key, 1024, 0666 | IPC_CREAT);
	if (shmid == -1)
	{
		perror ("shmget");
		exit (EXIT_FAILURE);
	}

	char *shared_memory = (char *) shmat(shmid, NULL, 0);
	if (shared_memory == (char *)(-1) )
	{
		perror("shmat");
		exit (EXIT_FAILURE);
	}

	strcpy (shared_memory,  "Hello, shared memory");
	printf ("Data written to shared memory: %d\n", shared_memory);
	shmdt (shared_memory);


	return 0;


}
