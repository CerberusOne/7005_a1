#include "server.h"

using namespace std;

Server::Server(int listenPort) {
    socklen_t cmdlen;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	SetReuse(listenfd);
	ConfigServerSocket(&servaddr, listenPort);
	Bind(listenfd, &servaddr);
	Listen(listenfd, LISTENQ);	//LISTENQ = 5

    //accept a connection
	cmdfd = Accept(listenfd, (struct sockaddr*)&cmdaddr, &cmdlen);

    //get the ip address from the connection
    inet_ntop(AF_INET, &cmdaddr.sin_addr.s_addr, transferIP, INET_ADDRSTRLEN);
}

const char *Server::GetTransferIP()
{
    return transferIP;
}

//MOVE TO MAINWINDOW Checks the type of command
const Cmd Server::WaitCommand() {
	char *buff = (char*)malloc(BUFLEN);

	printf("Waiting for command...\n");
	memset(&buff[0], 0, BUFLEN);
	fflush(stdin);

	return RecvCmd(cmdfd);
}



