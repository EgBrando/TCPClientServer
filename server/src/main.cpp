#include "Server.h"

int main()
{
    int port;
    std::cout << "Enter the port: ";
    std::cin >> port;
    Server server(port);
    server.serverRun();

    return 0;
}