#include <iostream>
#define HOURS_PER_DAY 24
#define MINS_PER_HOUR 60
using namespace std;

struct Time {
	int days;
	int hours;
	int mins;
};

Time add_time (Time time1, Time time2);

Time subtract_time (Time time1, Time time2);

void show_time (Time time);

int main () {
	Time time_1 = {
		2,
		17,
		24
	};
	Time time_2 = {
		3,
		21,
		55
	};

	Time sum = add_time (time_1, time_2);
	Time sub = subtract_time (time_1, time_2);
	cout << "the one time:" << endl;
	show_time (time_1);
	cout << "the other time:" << endl;
	show_time (time_2);
	cout << endl;
	cout << "the sum:" << endl;
	show_time (sum);
	cout << "the subtraction:" << endl;
	show_time (sub);

}


Time add_time (Time time1, Time time2) {
	Time result;
	//one way
	result.mins = (time1.mins + time2.mins) % MINS_PER_HOUR;
	result.hours = ((time1.mins + time2.mins) / MINS_PER_HOUR +
		(time1.hours + time2.hours)) % HOURS_PER_DAY;
	result.days = (time1.days + time2.days) +
		(time1.hours + time2.hours + (time1.mins + time2.mins) / MINS_PER_HOUR) / HOURS_PER_DAY;
	return result;
}

Time subtract_time (Time time1, Time time2) {
	Time result;
	//the other way 
	int total_mins = (time1.days - time2.days) * HOURS_PER_DAY * MINS_PER_HOUR +
		(time1.hours - time2.hours) * MINS_PER_HOUR + (time1.mins - time2.mins);
	if ( total_mins < 0 )
		total_mins = -total_mins;
	result.mins = total_mins % MINS_PER_HOUR;
	result.hours = (total_mins / MINS_PER_HOUR) % HOURS_PER_DAY;
	result.days = (total_mins / MINS_PER_HOUR) / HOURS_PER_DAY;
	return result;
}

void show_time (Time time) {
	cout << "DAYS:" << time.days << endl;
	cout << "HOURS:" << time.hours << endl;
	cout << "MINS:" << time.mins << endl;
}