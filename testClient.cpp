#include "A1/client.h"
#include "A1/server.h"

using namespace std;

int main (int argc, char *argv[]) {
	string userInput = "";

	Client *commandClient = new Client("127.0.0.1", 7005);
	Server *transferServer = new Server(70005);
	

	return 0;
}

