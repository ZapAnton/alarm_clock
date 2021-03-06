#include "alarm_utils.h"

void get_await_time(await_time* await_time, int argc, char** argv) {
	char input_param;
	
	while ((input_param = getopt(argc, argv, "h:m:s:")) != -1) {
		switch (input_param) {
			case 's':
				await_time->seconds = atoi(optarg);
				break;
			case 'm':
				await_time->minutes = atoi(optarg);
				break;
			case 'h':
				await_time->hours = atoi(optarg);
				break;
		}
	}
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