/*****************************************************************************
 * SERVER SIDE
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <math.h>

int newsockfd;
float Calculator();

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0){
		error("ERROR opening socket");
	}

	bzero((char *) &serv_addr, sizeof(serv_addr)); // Writes zeroes to a byte string

	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET; // the internet
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		error("ERROR on binding");
	}

	//	NOW IT WAITS FOR A CONNECTION

	listen(sockfd,5); // Can accept up to 5 connections in the same time
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);

	if (newsockfd < 0){
		error("ERROR on accept");
	}

	// THE COMMUNICATIONs HAPPENS HERE

	Calculator();

	bzero(buffer,256); // Again writes 0's to the byte string
	n = read(newsockfd,buffer,255);

	if (n < 0){ 
		error("ERROR reading from socket");
	}

	printf("Here is the message: %s\n",buffer);
	n = write(newsockfd,"I got your message",18);

	if (n < 0){
		error("ERROR writing to socket");
	}

	// Closing the sockets
	close(newsockfd);
	close(sockfd);
	return 0;
}

float Calculator(){

	while (1){ 
		float op_1, op_2, result; 
		char operator;
    
		read(newsockfd, &op_1, sizeof(float));
		read(newsockfd, &operator, sizeof(char));
		read(newsockfd, &op_2, sizeof(float));

		// Switch-case for the operators (+,-,*,/)
		switch(operator){
			case '+':{ // For the "+" operator
				result = (op_1 + op_2);
				break;
			}
			case '-':{ // For the "-" operator
				result = (op_1 - op_2);
				break;
			}
			case '*':{ // For the "*" operator
				result = (op_1 * op_2);
				break;
			}
			case '/':{ // For the "/" operator
				result = (op_1 / op_2);
				break;
			}
		}
		write(newsockfd, &result, sizeof(float));
	}
}
