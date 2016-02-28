#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>

#define die(msg) do{perror(msg); exit(EXIT_FAILURE);}while(0)

#define PORT "4242"
#define NUM_CHILDREN 3

#define MAXLEN 1024

int readline(int fd, char* buf, int maxlen);

int 
main(int argc, char** argv)
{
	int i, n, sockfd, clientfd;
	int yes = 1;
	struct addrinfo *ai;
	struct sockaddr_in *client;
	socklen_t client_t;
	pid_t cpid;
	char line[MAXLEN];
	char cpid_s[32];

	char welcom[32];
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
}
