#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "await_time.h"

void get_await_time(await_time* await_time, int argc, char** argv);

void wait_before_alarm(await_time* await_time);
