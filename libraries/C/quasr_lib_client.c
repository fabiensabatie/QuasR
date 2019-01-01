#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"

#define QUASR_SOCKET_PORT 8084
#define QUASR_SOCKET_ADDR INADDR_ANY

int main(int argc, char *argv[])
{
	int								client_socket;
	struct sockaddr_in				socket_address;
	char							*quasr_function_response;

	client_socket					= socket(AF_INET, SOCK_STREAM, 0);
	socket_address.sin_addr.s_addr	= QUASR_SOCKET_ADDR;
	socket_address.sin_family		= AF_INET;
	socket_address.sin_port			= htons(QUASR_SOCKET_PORT);

	if (connect(client_socket, (const struct sockaddr *) &socket_address, sizeof(socket_address)) < 0) {
		printf("Failed to connect to the server.\n\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Connected to the server !\n");
	while (1) {
		ft_printf("Send a message to the server : ");
		get_next_line(0, &quasr_function_response);
		ft_printf("Sending \"%s\"\n", quasr_function_response);
		if (write(client_socket, quasr_function_response, sizeof(char) * ft_strlen(quasr_function_response)) < 0) {
			printf("Failed to write the message to the socket");
			exit(EXIT_FAILURE);
		}
		// if (read(client_socket, quasr_function_response, sizeof(quasr_function_response)) < 0) {
		// 	printf("Failed to read the message from the server");
		// 	exit(EXIT_FAILURE);
		// }
		// printf("Recieved %s from the server\n", quasr_function_response);
	}

	return 0;
}
