#include "A1/client.h"
#include "A1/server.h"

using namespace std;

int main (int argc, char *argv[]) {
	string userInput = "";

	Server *server = new Server(7005);
	Client *client = new Client("127.0.0.1", 70005);
	
	return 0;
}

