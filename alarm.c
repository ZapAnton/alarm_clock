#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

void start_alarm(void);

void stop_alarm(void);

int main(int argc, char** argv) {
	start_alarm();
	
	stop_alarm();
		
	return 0;
}

void start_alarm(void) {
	#ifdef _WIN32	
	PlaySound(TEXT("files\\alarm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	#endif

	for (int i = 0; i < 5; ++i) {
		printf("WAITING %d...\n", i);
		Sleep(1000);
	}	
}

void stop_alarm(void) {
	
	
	#ifdef _WIN32	
	if (!PlaySound(NULL, 0, 0)) {
		puts("COULD NOT STOP SOUND");
	}	
	#endif
}
