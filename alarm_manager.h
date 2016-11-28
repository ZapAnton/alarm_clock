#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

void start_alarm(void);

void stop_alarm(void);