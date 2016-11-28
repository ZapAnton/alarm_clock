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

void wait_before_alarm(int);

int main(int argc, char** argv) {
	char input_param;
	
	int seconds_to_wait = 0;
	
	while ((input_param = getopt(argc, argv, "s:")) != -1) {
		switch (input_param) {
			case 's':
				seconds_to_wait = atoi(optarg);
				break;
		}
	}
	
	wait_before_alarm(seconds_to_wait);
		
	start_alarm();
	
	stop_alarm();
		
	return 0;
}

void wait_before_alarm(int seconds_to_wait) {
	printf("Alarm is set to start in %d seconds\n", seconds_to_wait);
	
	#ifdef _WIN32
	Sleep(seconds_to_wait * 1000);
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
