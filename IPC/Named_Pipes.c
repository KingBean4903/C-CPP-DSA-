#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {

	const char *fifo = "myfifo";

	// Create the FIFO (named pipe)
	if (mkfifo (fifo, 0666) == -1)
	{
			perror("mkfifo");
	}

	pid_t pid = fork ();
	if (pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		char buffer[100];
		int fd = open (fifo, O_RDONLY);
		if (fd == -1) 
		{
			perror("open");
			exit (EXIT_FAILURE);
		}
		const char *msg = "Hello through FIFO";
		write(fd, msg, strlen(msg) + 1);
		close(fd);
	}
	return 0;
}
