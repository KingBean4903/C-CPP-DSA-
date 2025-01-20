#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/my_socket"

int main(void) 
{
	int client_fd;
	struct sockaddr_un server_addr;
	char buffer[100];


	// Create a Unix domain socket
	client_fd = socket (AF_UNIX, SOCK_STREAM, 0);
	if (client_fd == -1)
	{
		perror("socket");
		exit (EXIT_FAILURE);
	}
	
	// Configure the server address structure
	memset(&server_addr, 0, sizeof(struct sockaddr_un));
	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, SOCKET_PATH, 
			sizeof(server_addr.sun_path) - 1);

	// Connect to the server
	if (connect (client_fd, (struct sockaddr *) &server_addr, 
				sizeof(struct sockaddr_un)) == -1)
	{
		perror ("connect");
		close (client_fd);
		exit (EXIT_FAILURE);
	}

	// Send a message to the server
	const char *message = "Hello Server!";
	write (client_fd, message, strlen(message) + 1);
	printf ("Client sent; %s\n", message);

	// Receive a response from the server
	read (client_fd,  buffer, sizeof(buffer));
	printf ("Client received: %s\n", buffer);

	// Close the socket
	close (client_fd);

	return 0;

}
