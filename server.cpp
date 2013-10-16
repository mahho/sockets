#include "server.h"

CServer::CServer() {
}

int CServer::init() {
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// if (sockfd < 0)  TODO: zwracanie errora
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = 10864;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) {
		return 1;
	}
	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	return 0;
}

int CServer::getSocketState() {
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	pid_t pid = fork();

	if (pid == 0) {
		close(sockfd);
		return true;
	}
	else
		return false;
}

int CServer::getSocket() {
	return newsockfd;
}

std::string CServer::receive(int sock) {
	bzero(buffer,256);
	n = read(sock,buffer,255);
	if (n < 0) {
		close(sock);
		exit(0);
	} else
		return buffer;
}

void CServer::send(int sock, std::string data) {
	n = write(sock,data.c_str(),data.length());
}

void CServer::closeSocket() {
	close(newsockfd);
}
