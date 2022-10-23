#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXBUF 1024

int main(int argc, char **argv)
{
	int server_sockfd; int client_sockfd[3];
	int client_len[3]; int n;
	char buf[3][MAXBUF];

	char bufcpy[100];
	char bufcpy2[100];
	char bufcpy3[100];

	struct sockaddr_in clientaddr[3]; struct sockaddr_in serveraddr;
	for(int x = 0 ; x < 3 ; x++)client_len[x] = sizeof(clientaddr[x]);
	if ((server_sockfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP )) == -1)
	{
		perror("socket error : ");
		exit(0);
	}

	memset(&serveraddr, 0x00, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));

	bind(server_sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	listen(server_sockfd, 5);


	while(1)
	{
		for(int x = 0 ; x < 3 ; x++) {
			client_sockfd[x] = accept(server_sockfd, (struct sockaddr *)&(clientaddr[x]),
			&(client_len[x]));
	
			printf("New Client Connect[%d]: %s\n",x+1, inet_ntoa(clientaddr[x].sin_addr));
			memset(buf[x], 0x00, MAXBUF);
		}

		for (int x = 0; x < 3; x++) {
			if ((n = read(client_sockfd[x], buf[x], MAXBUF)) <= 0)
			{
				close(client_sockfd[x]);
				continue;
			}
			if (x <= 0) strcat(bufcpy, buf[x]);
			if (x <= 1) strcat(bufcpy2, buf[x]);
			if (x <= 2) strcat(bufcpy3, buf[x]);
		}
		
		for(int x = 0; x < 3 ; x++){
			if (x == 0) {
				if (write(client_sockfd[x], bufcpy, MAXBUF) <= 0)
				{
					perror("write error : ");
					close(client_sockfd[x]);
				}
				close(client_sockfd[x]);
			}
			if (x == 1) {
				if (write(client_sockfd[x], bufcpy2, MAXBUF) <= 0)
				{
					perror("write error : ");
					close(client_sockfd[x]);
				}
				close(client_sockfd[x]);
			}
			if (x == 2) {
				if (write(client_sockfd[x], bufcpy3, MAXBUF) <= 0)
				{
					perror("write error : ");
					close(client_sockfd[x]);
				}
				close(client_sockfd[x]);
			}
		}
	}
	close(server_sockfd);
	return 0;
}
