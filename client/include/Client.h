#ifndef CLIENT_INCLUDED
#define CLIENT_INCLUDED

#include <iostream>
#include <thread>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <assert.h>

class Client
{
public:
    Client(int port, std::string name, int tick);
    ~Client(){};

public:
    int clientConnect();
    void func();
    void clientRun();

private:
    std::string name;
    int tick;
    int sockfd;
    struct sockaddr_in serverAddr;
};

#endif