#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "await_time.h"

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

void start_alarm(void);

void stop_alarm(void);

void wait_before_alarm(await_time* await_time);

int main(int argc, char** argv) {
	char input_param;
	
	await_time await_time = {.seconds = 0, .minutes = 0, .hours = 0};
		
	while ((input_param = getopt(argc, argv, "h:m:s:")) != -1) {
		switch (input_param) {
			case 's':
				await_time.seconds = atoi(optarg);
				break;
			case 'm':
				await_time.minutes = atoi(optarg);
				break;
			case 'h':
				await_time.hours = atoi(optarg);
				break;
		}
	}
	
	wait_before_alarm(&await_time);
		
	start_alarm();
	
	stop_alarm();

	return 0;
}

void wait_before_alarm(await_time *await_time) {
	printf(
		"Alarm is set to start in %d hours %d minutes %d seconds\n", 
		await_time->hours, 
		await_time->minutes, 
		await_time->seconds
	);
	
	#ifdef _WIN32
	Sleep(await_time_to_milis(await_time));
	#endif
}

void start_alarm(void) {
	#ifdef _WIN32	
	PlaySound(TEXT("files\\alarm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	for (int i = 0; i < 5; ++i) {
		printf("WAITING %d...\n", i);
		Sleep(1000);
	}	
	
	#endif
}

void stop_alarm(void) {
	#ifdef _WIN32	
	if (!PlaySound(NULL, 0, 0)) {
		puts("COULD NOT STOP SOUND");
	}	
	#endif
}
