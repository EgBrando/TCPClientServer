#include <Server.h>

Server::Server(int port)
{
    std::ofstream{"log.txt"};
    serverIp.sin_family = AF_INET;
    serverIp.sin_port = htons(port);
    serverIp.sin_addr.s_addr = htons(INADDR_ANY);

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
}

int Server::serverBind()
{
    int ret = bind(sockfd, (struct sockaddr *)&serverIp, sizeof(serverIp));
    assert(ret == 0);

    return 0;
}

int Server::serverListen(int maxbacklog)
{
    int ret = listen(sockfd, maxbacklog);
    assert(ret == 0);

    return 0;
}

void Server::serverAccept()
{
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    while (1)
    {
        int connfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientLen);
        std::thread mythread(std::mem_fn(&Server::func), this, connfd);
        mythread.detach();
    }
}

void Server::func(int connfd)
{
    while (1)
    {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        int ret = recv(connfd, buffer, sizeof(buffer), 0);
        if (ret)
        {
            // std::cout << std::this_thread::get_id() << " " << buffer << std::endl;
            out.open("log.txt", std::ios_base::app);
            if (out.is_open())
            {
                out << std::this_thread::get_id() << ": " << buffer << std::endl;
            }
            out.close();
        }
        else if (ret == 0)
        {
            std::cout << "Client is disconnect" << std::endl;
            close(connfd);
            break;
        }
    }
    close(sockfd);
}

void Server::serverRun()
{
    serverBind();
    serverListen(5);
    serverAccept();
}