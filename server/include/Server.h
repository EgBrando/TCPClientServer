#ifndef SERVER_INCLUDED
#define SERVER_INCLUDED

#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <functional>
#include <fstream>
#include <assert.h>

class Server
{
public:
    Server(int port);
    ~Server(){};

public:
    int serverBind();
    int serverListen(int maxbacklog);
    void serverAccept();
    void func(int connfd);
    void serverRun();

private:
    int sockfd;
    struct sockaddr_in serverIp;
    std::ofstream out;
};

#endif