#include "alarm_manager.h"

void run_alarm(void) {
	start_alarm();
	
	stop_alarm();
}

void start_alarm(void) {	
	#ifdef _WIN32	
	PlaySound(TEXT("files\\alarm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	for (int i = 0; i < 5; ++i) {
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