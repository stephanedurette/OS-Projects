/*
 * client.c
 *
 * This is a sample internet client application that will talk
 * to the server s.c via port 5000
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

char buffer[512];

int
main (int argc, char *argv[])
{
	int client_socket, len;
	struct sockaddr_in server_addr;
	struct hostent *host;

	/*
	 * check for sanity
	 */

	if (argc != 3) {
		printf ("usage: c IP_ADDRESS PORT_NUMBER\n");
		return 1;
	}	/* endif */

	/*
	 * get a socket for communications
	 */

	if ((client_socket = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		printf ("grrr, can't get a client socket!\n");
		return 3;
	}	/* endif */

	/*
	 * initialize struct to get a socket to host
	 */
	
	memset (&server_addr, 0, sizeof (server_addr));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (atoi(argv[2]));

	/*
	 * attempt a connection to server
	 */

	if (connect (client_socket, (struct sockaddr *)&server_addr,
	sizeof (server_addr)) < 0) {
		printf ("grrr, can't connet to server!\n");
		close (client_socket);
		return 4;
	}	/* endif */

	/*
	 * now that we have a connection, get a commandline from
	 * the user, and fire it off to the server
	 */
	while(1){
		system("clear");
		printf ("Select an Option:\n");
		printf ("1: [Who] command\n");
		printf ("2: [When] command\n");
		printf ("3: [Where] command\n");
		printf ("4: Display help information\n");
		printf ("5: Exit\n");
		printf ("Selection: ");
		fflush (stdout);
		fflush (stdin);
		memset(buffer,0,strlen(buffer));
		char* input = fgets(buffer, 512, stdin);
		int optionNumber = atoi(input);
		switch(optionNumber){
			case 1:
				strcpy(buffer, "who\0");
				write (client_socket, buffer, strlen (buffer));
				printf("%s\n", buffer);
				len = read (client_socket, buffer, sizeof (buffer));
				printf ("Result of command:\n%s\n\n", buffer);
				break;
			case 2:
				strcpy(buffer, "when\0");
				write (client_socket, buffer, strlen (buffer));
				len = read (client_socket, buffer, sizeof (buffer));
				printf ("Result of command:\n%s\n\n", buffer);
				break;
			case 3:
				strcpy(buffer, "where\0");
				write (client_socket, buffer, strlen (buffer));
				len = read (client_socket, buffer, sizeof (buffer));
				printf ("Result of command:\n%s\n\n", buffer);
				break;
			case 4:
				system("clear");
				printf ("Option Results:\n");
				printf ("1: [Who] command: returns 'INFO72220' from the server\n");
				printf ("2: [When] command: returns the current time from the server\n");
				printf ("3: [Where] command: returns 'Cambridge' from the server\n");
				printf ("4: Displays help information\n");
				printf ("5: Closes the server and exits the program\n");
				break;
			case 5:
				strcpy(buffer, "exit\0");
				write (client_socket, buffer, strlen (buffer));
				close (client_socket);
				exit(0);
				break;
			default:
				break;
		}
		
		printf("\nPress [Enter] to continue\n");
		char f[512];
		fgets(f, 512, stdin);
	}

	return 0;
}



