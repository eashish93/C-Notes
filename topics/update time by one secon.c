// Program to update the time by one second

#include <stdio.h>

typedef struct {
	int hour;
	int minutes;
	int seconds;
} t_time;

t_time timeUpdate(t_time now) {
	++now.seconds;

	if(now.seconds == 60) { // next minute
		now.seconds = 0;
		++now.minutes;

		if(now.minutes == 60) {
			now.minutes = 0;
			++now.hour;

			if(now.hour == 24)
				now.hour = 0;
		}

	}
	return now;
}

int main(void) {
	t_time timeUpdate(t_time now);	
	t_time currentTime, nextTime;

	printf("Enter the time (hh:mm:ss): ");
	scanf("%i:%i:%i", &currentTime.hour, &currentTime.minutes, &currentTime.seconds);

	nextTime = timeUpdate(currentTime);

	printf("Updated time is %.2i:%.2i:%.2i\n", nextTime.hour, nextTime.minutes, nextTime.seconds);

	return 0;

}