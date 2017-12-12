/*****************************************************************************
 * CLIENT SIDE
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h> // This is the socket library
#include <netinet/in.h>
#include <netdb.h>

int sockfd;
void Calculator();

void error(const char *msg)
{
	perror(msg); // For error messages
	exit(0);
}

int main(int argc, char *argv[])
{
	int portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];

	if (argc < 3) {
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}

	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0){
		error("ERROR opening socket");
	}

	server = gethostbyname(argv[1]);

	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr)); // Sets the entire address to 0's, wipes it out
	serv_addr.sin_family = AF_INET;

	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
		error("ERROR connecting");
	}

	Calculator();
	printf("Please enter the message: ");
	bzero(buffer,256);
	fgets(buffer,255,stdin);
	n = write(sockfd,buffer,strlen(buffer));

	if (n < 0){
		error("ERROR writing to socket");
	}

	bzero(buffer,256);
	n = read(sockfd,buffer,255);

	if (n < 0){
		error("ERROR reading from socket");
	}

	printf("%s\n",buffer);

	// Closing the socket
	close(sockfd);
	return 0;
}

void Calculator(){
	float op_1, op_2, result;
	char operator;

	printf("Please enter below which operation you wish to execute: \n");
	scanf("%f%c%f",&op_1,&operator,&op_2);

	// Writting to the socket
	write(sockfd,&op_1, sizeof(float));
	write(sockfd,&operator, sizeof(char));
	write(sockfd,&op_2, sizeof(float));

	read(sockfd,&result, sizeof(float));
	printf("Result of your calculation is %f\n", result);
}
