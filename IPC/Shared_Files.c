#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() { 

	int fd = open("shared_file.txt", O_WRONLY | O_CREATE, 0666);
	
	if (fd == -1) {
		perror("Open");
		exit(EXIT_FAILURE);
	}

	const char *message = "Hello, IPC world! \n";
	if (write(fd, message, strlen(message)) == -1) 
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	
	close (fd);

	return 0;
}
