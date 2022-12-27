/* 
 The raise() Function
 You can generate signals by function raise(), which takes an integer signal number as an argument and has the following syntax.

 int raise (signal sig);
 Here, sig is the signal number to send any of the signals: SIGINT, SIGABRT, SIGFPE, SIGILL, SIGSEGV, SIGTERM, SIGHUP.
 */

#include <iostream>
#include <unistd.h>		// header for sleep
#include <csignal>		// header for signal function

using namespace std;

void signalHandler(int signum) {		// signal handler function
	cout << "Interrupt signal (" << signum << ") received.\n";

	// cleanup and close up stuff here
	// terminate program

	// tasks to be executed when this signal is received

	exit(signum);		// return signal to OS upon exit
}

int main() {
	int i = 0;
	// register signal SIGINT and signal handler
	signal(SIGINT, signalHandler);		// tells, execute "signalHandler" when "SIGINT" signal is received

	while (++i) {
		cout << "Going to sleep...." << endl;
		if (i == 3) {
			raise (SIGINT);			// raising SIGINT signal internally
		}
		sleep(1);
	}

	return 0;
}
