#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

int main(int argc, char** argv) {
	
	PlaySound(TEXT("files\\alarm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	sleep(5000);
	
	return 0;
}