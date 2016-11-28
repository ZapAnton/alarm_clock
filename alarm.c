#include "await_time.h"
#include "alarm_utils.h"
#include "alarm_manager.h"

int main(int argc, char** argv) {	
	await_time await_time = {.seconds = 0, .minutes = 0, .hours = 0};
	
	get_await_time(&await_time, argc, argv);
	
	wait_before_alarm(&await_time);
		
	start_alarm();
	
	stop_alarm();

	return 0;
}
