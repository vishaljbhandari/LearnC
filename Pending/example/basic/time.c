#include <stdio.h>
#include <time.h>

const char *weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday" };
const char *month[] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };

const static int bufSize = 128;

int main() {
	time_t tmt;
	struct tm gmt = *gmtime(&tmt);	// structured time in GMT
	struct tm localt = *localtime(&tmt);	// structured time local
	printf("direct from struct tm:\n");
	printf("universal time is now %04d-%02d-%02d %02d:%02d:%02d\n",
			gmt.tm_year + 1900, gmt.tm_mon, gmt.tm_mday, gmt.tm_hour,
			gmt.tm_min, gmt.tm_sec);

	char buf[bufSize];	// buffer for strftime

	size_t len = strftime(buf, bufSize, "%Y-%m-%d %H:%M:%S", &gmt);
	printf("from strftime (gmt):\n");
	printf("universal time is now %s (%ld characters)\n", buf, len);

	len = strftime(buf, bufSize, "%Y-%m-%d %H:%M:%S %Z", &localt);
	printf("from strftime (localt):\n");
	printf("local time is now %s (%ld characters)\n", buf, len);

	time_t now;
	struct tm *timestamp;

	printf("It's now %ld\n", time(NULL));	// the current time
	printf("It's now %s\n", time(NULL));	// the current time

	time(&now);
	printf("It's now %ld\n", now);
	printf("It's now %s", ctime(&now));
	printf("%s", ctime(&now));
	timestamp = localtime(&now);
	printf("Today is %s, %s %d %d\n", weekday[timestamp->tm_wday],
			month[timestamp->tm_mon], timestamp->tm_mday,
			timestamp->tm_year + 1900);
	printf("It's now %d:%02d:%02d\n", timestamp->tm_hour, timestamp->tm_min,
			timestamp->tm_sec);

	return (0);
}
