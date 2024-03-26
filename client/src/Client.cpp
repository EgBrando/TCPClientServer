#include "Client.h"
#include "DateTime.h"

Client::Client(int port, std::string name, int tick)
{
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    this->name = name;
    this->tick = tick;
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
}

int Client::clientConnect()
{
    int ret = connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    assert(ret == 0);

    return 0;
}

void Client::func()
{
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(tick));

        char bufferTime[84];
        DateTime::getCurrentTimeWithMs(bufferTime);
        std::string time = bufferTime;
        std::string s = "[" + time + "] " + name;
        send(sockfd, s.c_str(), sizeof(s), 0);
    }

    close(sockfd);
}

void Client::clientRun()
{
    clientConnect();
    func();
}