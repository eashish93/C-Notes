// Program to print the tomorrow's date

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int day;
	int month;
	int year;
} date;


void *dateUpdate(date *today) {
	date *tomorrow = today;
	bool isLeapYear(date *today);
	const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if((isLeapYear(today) && today->month == 2 && today->day == 28) || today->day != daysPerMonth[today->month - 1]) {
		tomorrow->day = today->day + 1;
		tomorrow->month = today->month;
		tomorrow->year = today->year;
	} 

	else if(today->month == 12) {
		tomorrow->day = 1;
		tomorrow->month = 1;
		tomorrow->year = today->year + 1;
	}

	else {
		tomorrow->day = 1;
		tomorrow->month = today->month + 1;
		tomorrow->year = today->year;
	}

}

// Function to determine if it's a leap year

bool isLeapYear(date *d) {
	if((d->year % 4 == 0 && d->year % 100 != 0) || d->year % 400 == 0)
		return true;
	else
		return false;
}


int main(void) {

	date thisDay, *nextDay;

	printf("Enter today's date (mm dd yyyy): ");
	scanf("%2i%2i%4i", &thisDay.month, &thisDay.day, &thisDay.year);

	nextDay = dateUpdate(&thisDay);
	printf("Tomorrow Date is %i/%i/%.2i", nextDay->month, nextDay->day, nextDay->year % 100);

	return 0;
}

