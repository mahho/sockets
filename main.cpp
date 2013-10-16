#include <iostream>
#include <errno.h>


#include "server.h"
CServer myServer;

void handle(int sock) {
	while (1) {
		std::string received = myServer.receive(sock);
		std::cout << "Received: " << received;
		std::cout << "Sending confirmation" << std::endl;
		myServer.send(sock, "confirm\n\r");
	}
}

int main() {
	signal(SIGCHLD,SIG_IGN);
	
	myServer.init();
	while (1) {
		if (myServer.getSocketState()) {
			handle(myServer.getSocket());
		} else {
			myServer.closeSocket();
		}
	}

    return 0;
}
