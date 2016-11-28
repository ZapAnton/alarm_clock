cd src
gcc -std=c11 -o ..\\alarm.exe alarm.c await_time.c alarm_manager.c alarm_utils.c -Iinclude -lwinmm
cd ..