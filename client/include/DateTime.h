#ifndef DATETIME_INCLUDED
#define DATETIME_INCLUDED

#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>

class DateTime
{
public:
    static void getCurrentTimeWithMs(char *currentTime)
    {
        timeval curTime;
        gettimeofday(&curTime, NULL);
        int milli = curTime.tv_usec / 1000;

        int bufSize = 80;
        char buffer[bufSize];
        struct tm m_time;
        long int s_time = time(NULL);
        localtime_r(&s_time, &m_time);
        strftime(buffer, bufSize, "%Y-%m-%d %H:%M:%S", &m_time);

        sprintf(currentTime, "%s:%03d", buffer, milli);
    }
};
#endif