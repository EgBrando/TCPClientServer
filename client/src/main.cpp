#include "Client.h"

int main()
{
    std::string name = "";
    int port, tick;
    std::cout << "Enter the name, port and period in second: ";
    std::cin >> name >> port >> tick;
    Client client(port, name, tick);
    client.clientRun();
}
