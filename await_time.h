#ifndef AWAIT_TIME_H
#define AWAIT_TIME_H

typedef struct await_time {
	int seconds;
	int minutes;
	int hours;
} await_time;

long await_time_to_milis(await_time* await_time);

#endif