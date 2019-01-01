#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "libft/includes/libft.h"

/** Error messages defines */
#define QUASR_SOCKET_BIND_ERROR "Failed to connect to the bind the socket to the provided address."
#define QUASR_SOCKET_CLIENT_READ_ERROR "Failed to read the client's message."
#define QUASR_SOCKET_ANSWER_ERROR "Failed to respond to the client."

/** Socket header constants */
#define QUASR_H_HEAD "QUASR_HEAD"
#define QUASR_H_HEAD_SIZE 10 // Length of the QUASR_H_HEAD string

/** Socket values defines */
#define QUASR_SOCKET_PORT 8084
#define QUASR_SOCKET_ADDR INADDR_ANY
#define QUASR_SOCKET_BUFFER_SIZE 1024
#define QUASR_SOCKET_HEADER_SIZE 96 // sizeof(QuasR_Header);
#define QUASR_SOCKET_CLOSE "QUASR_ON_END"

typedef struct				s_QuasR_Header
{
	char					head[QUASR_H_HEAD_SIZE];
	char					ipv4_origin[15];
	char					user_id[30];
	char					user_private_key[30];
	char					*message;
	unsigned long long int	data_size;
}							QuasR_Header;

int __ERROR(char *message) {
	printf("%s : %i\n", message, errno);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int									server_socket;
	int									client_socket;
	struct sockaddr_in					socket_address;
	char								quasr_server_response[QUASR_SOCKET_BUFFER_SIZE];
	char								quasr_client_buffer[QUASR_SOCKET_BUFFER_SIZE];

	server_socket						= socket(AF_INET, SOCK_STREAM, 0);
	socket_address.sin_addr.s_addr		= QUASR_SOCKET_ADDR;
	socket_address.sin_family			= AF_INET;
	socket_address.sin_port				= htons(QUASR_SOCKET_PORT);

	// Binding the socket to the server
	if (bind(server_socket, (struct sockaddr *) &socket_address, sizeof(socket_address)) < 0)
		__ERROR(QUASR_SOCKET_BIND_ERROR);

	// Listening for connections
	listen(server_socket, 1);
	ft_printf("Awaiting user message...\n");
	// Waiting for a user to connect
	client_socket = accept(server_socket, NULL, NULL);
	while (1) {
		// Reading the user's message
		if (read(client_socket, quasr_client_buffer, QUASR_SOCKET_BUFFER_SIZE) < 0)
			__ERROR(QUASR_SOCKET_CLIENT_READ_ERROR);
		// If the user is closing the socket, break the loop
		if (!strcmp(quasr_client_buffer, QUASR_SOCKET_CLOSE)) break;
		ft_printf("The server got a message : %s\n", quasr_client_buffer);
		ft_bzero(quasr_client_buffer, sizeof(char) * ft_strlen(quasr_client_buffer));
		// // Echoing back
		// if (write(client_socket, quasr_server_response, sizeof(quasr_server_response) < 0))
		// 	__ERROR(QUASR_SOCKET_ANSWER_ERROR);
	}
	return 0;
}
