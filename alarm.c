#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <unistd.h>
#endif

int main(int argc, char** argv) {
	#ifdef _WIN32	
	PlaySound(TEXT("files\\alarm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	#endif	
	
	for (int i = 0; i < 5; ++i) {
		printf("WAITING %d...\n", i);
		Sleep(1000);
	}
		
	if (!PlaySound(NULL, 0, 0)) {
		puts("COULD NOT STOP SOUND");
	}
	
	return 0;
}