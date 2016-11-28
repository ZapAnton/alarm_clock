#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

void start_alarm(void);

void stop_alarm(void);

void wait_before_alarm(int seconds_to_wait, int minutes_to_wait, int hours_to_wait);

int main(int argc, char** argv) {
	char input_param;
	
	int seconds_to_wait = 0;
	int minutes_to_wait = 0;
	int hours_to_wait = 0;
	
	while ((input_param = getopt(argc, argv, "h:m:s:")) != -1) {
		switch (input_param) {
			case 's':
				seconds_to_wait = atoi(optarg);
				break;
			case 'm':
				minutes_to_wait = atoi(optarg);
				break;
			case 'h':
				hours_to_wait = atoi(optarg);
				break;
		}
	}
	
	wait_before_alarm(seconds_to_wait, minutes_to_wait, hours_to_wait);
		
	start_alarm();
	
	stop_alarm();
		
	return 0;
}

void wait_before_alarm(int seconds_to_wait, int minutes_to_wait, int hours_to_wait) {
	printf(
		"Alarm is set to start in %d hours %d minutes %d seconds\n", 
		hours_to_wait, 
		minutes_to_wait, 
		seconds_to_wait
	);
	
	#ifdef _WIN32
	Sleep(( (hours_to_wait * 3600) + (minutes_to_wait * 60) + seconds_to_wait) * 1000);
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
