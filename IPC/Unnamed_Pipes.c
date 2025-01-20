#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

enum 
{
	READ_END = 0,
	WRITE_END = 1,
	NUM_PIPES = 2,
} pipe_fds;

int main(void) 
{
	int pipefd[NUM_PIPES];
	pid_t pid;
	char buffer[100];

	if (pipe(pipefd) == -1) 
	{
		perror("pipe");
		exit (EXIT_FAILURE);
	}

	pid =fork();
	if (pid == -1) 
	{
		perror ("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		close (pipefd[WRITE_END]);
		read (pipefd[READ_END], buffer, sizeof(buffer));
		printf("Child received: %s\n", buffer);
		close (pipefd[READ_END]);
	} else {
		
		close (pipefd[READ_END]);
		const char *msg =  "Message from parent";
		write (pipefd[WRITE_END], msg, strlen (msg) + 1);
		close (pipefd[WRITE_END]);
	
	}

	return 0;

}
