#ifndef __SERVER_H_
#define __SERVER_H_

#include <cstdlib>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

class CServer {
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;	


public:
	CServer();
	int init();
	std::string receive(int sock);
	void send(int sock, std::string data);
	int getSocket();
	int getSocketState();
	void closeSocket();
	void checkSockets();
};

#endif
