#include <stdio.h>
#include <string.h>

struct weather {
	char day[10];
	float temp;
};

float avgOfTemperature(struct weather week[]) {
	float sum = 0.0;
	int index = 0;
	for(;index < 7;) {
		sum += week[index++].temp;
	}
	return sum/7.0;
}

int main() {

	struct weather week[7];
	int x;

	strcpy(week[0].day, "Sunday");
	week[0].temp = 72.5;
	strcpy(week[1].day, "Monday");
	week[1].temp = 68.4;
	strcpy(week[2].day, "Tuesday");
	week[2].temp = 75.0;
	strcpy(week[3].day, "Wednesday");
	week[3].temp = 73.8;
	strcpy(week[4].day, "Thursday");
	week[4].temp = 65.1;
	strcpy(week[5].day, "Friday");
	week[5].temp = 72.8;
	strcpy(week[6].day, "Saturday");
	week[6].temp = 75.2;

	puts("This week's forecast:");
	for (x = 0; x < 7; x++)
		printf("%10s %.1f degrees\n", week[x].day, week[x].temp);

	struct weather week1[7] = { { "Sunday", 72.5 }, { "Monday", 68.4 }, {
			"Tuesday", 75.0 }, { "Wednesday", 73.8 }, { "Thursday", 65.1 }, {
			"Friday", 72.8 }, { "Saturday", 75.2 } };

	struct weather today = { "Sunday", 72.5 };
	puts("\nToday's forecast:");
	printf("%10s %.1f degrees\n", today.day, today.temp);

	puts("\nThis week's forecast:");
	for (x = 0; x < 7; x++)
		printf("%10s %.1f degrees\n", week1[x].day, week1[x].temp);

	week1[1] = week1[5];	// Assigning structure object

	puts("\nThis week's forecast:");
	for (x = 0; x < 7; x++)
		printf("%10s %.1f degrees\n", week1[x].day, week1[x].temp);

	printf("Average Temp - %f\n", avgOfTemperature(week));
	return 0;
}
