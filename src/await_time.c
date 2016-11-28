#include "await_time.h"

long await_time_to_milis(await_time* await_time) {
	return ( (await_time->hours * 3600) + (await_time->minutes * 60) + await_time->seconds) * 1000; 
}