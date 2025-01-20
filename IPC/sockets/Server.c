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
	
	// Create a unix domain socket
	client_fd = socket (AF_UNIX, SOCK_STREAMM, 0);
	if (client_fd == -1)
	{
		perror("socket");
		exit (EXIT_FAILURE);
	}
	
	// Remove any existing socket file
	unlink (SOCKET_PATH);
	
	// COnfigure the server address structure
	memset (&server_addr, 0, sizeof (struct sockaddr_un));
	server_addr.sun_family = AF_UNIX;
	strncpy (server_addr.sun_path, SOCKET_PATH, 
			sizeof (server_addr.sun_path) - 1);

	// Bind the socket to the address
	if (bind (server_fd, (struct sockaddr *) &server_addr,
				sizeof (struct sockaddr_un)) == -1)
	{
			perror("bind");
			close (server_fd);
			exit (EXIT_FAILURE);
	}

	// Listen for incoming connections
	if (listen (server_fd, 5) == -1)
	{
			perror("listen");
			close (server_fd);
			exit (EXIT_SERVER);
	}

	printf("Server listening on %s\n", SOCKET_PATH);

	// Accept a client connection
	client_fd = accept (server_fd, NULL, NULL);
	if (client_fd == -1)
	{
		perror("accept");
		close (server_fd);
		exit (EXIT_FAILURE);
	}
	
	// Read data from the client
	read (client_fd, buffer, sizeof(buffer));
	printf("Server received: %s\n", buffer);

	// Send a response to the client
	const char *response = "Hello from server";
	write (client_fd, response, strlen (response) + 1);

	// Close sockets
	close (client_fd);
	close (server_fd);
	unlink (SOCKET_PATH);

	return 0;

}

