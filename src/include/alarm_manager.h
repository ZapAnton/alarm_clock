#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

void run_alarm(void);
