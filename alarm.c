#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

struct await_time {
	int seconds;
	int minutes;
	int hours;
};

void start_alarm(void);

void stop_alarm(void);

void wait_before_alarm(struct await_time* await_time);


int main(int argc, char** argv) {
	char input_param;
	
	int seconds_to_wait = 0;
	int minutes_to_wait = 0;
	int hours_to_wait = 0;
	
	struct await_time at = {.seconds = 0, .minutes = 0, .hours = 0};
		
	while ((input_param = getopt(argc, argv, "h:m:s:")) != -1) {
		switch (input_param) {
			case 's':
				at.seconds = atoi(optarg);
				break;
			case 'm':
				at.minutes = atoi(optarg);
				break;
			case 'h':
				at.hours = atoi(optarg);
				break;
		}
	}
	
	wait_before_alarm(&at);
		
	start_alarm();
	
	stop_alarm();

	return 0;
}

void wait_before_alarm(struct await_time *await_time) {
	printf(
		"Alarm is set to start in %d hours %d minutes %d seconds\n", 
		await_time->hours, 
		await_time->minutes, 
		await_time->seconds
	);
	
	#ifdef _WIN32
	Sleep(( (await_time->hours * 3600) + (await_time->minutes * 60) + await_time->seconds) * 1000);
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
