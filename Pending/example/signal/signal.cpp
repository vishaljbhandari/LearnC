// gcc -lstdc++ -lm signal.cpp

/* Signals

 Signals are the interrupts delivered to a process by the operating system which can terminate a program prematurely.
 You can generate interrupts by pressing Ctrl+C on a UNIX, LINUX, Mac OS X or Windows system.

 There are signals which can not be caught by the program
 but there is a following list of signals which you can catch in your program and can take appropriate actions based on the signal.
 These signals are defined in C++ header file <csignal>.

 Sr.No	Signal & Description
 SIGABRT : Abnormal termination of the program, such as a call to abort.
 SIGFPE : An erroneous arithmetic operation, such as a divide by zero or an operation resulting in overflow.
 SIGILL : Detection of an illegal instruction.
 SIGINT : Receipt of an interactive attention signal.
 SIGSEGV : An invalid access to storage.
 SIGTERM : A termination request sent to the program.

 */

/*

 C++ signal-handling library provides function signal to trap unexpected events. Following is the syntax of the signal() function −
 Defined in header <csignal>

 void (*signal (int sig, void (*func)(int)))(int);


 // signal-handler
 // signal(int sig, signal-handler);
 // extern "C" using signal-handler = void(int); // exposition-only

 sig - the signal to set the signal handler to. It can be an implementation-defined value or one of the following values:
 SIGABRT
 SIGFPE
 SIGILL
 SIGINT
 SIGSEGV
 SIGTERM

 handler - the signal handler. This must be one of the following:
 SIG_DFL macro. The signal handler is set to default signal handler.
 SIG_IGN macro. The signal is ignored.
 pointer to a function.
 The signature of the function must be equivalent to the following:
 extern "C" void fun(int sig);

 Keeping it simple, this function receives two arguments:
 first argument as an integer which represents signal number
 second argument as a pointer to the signal-handling function.

 Let us write a simple C++ program where we will catch SIGINT signal using signal() function.
 Whatever signal you want to catch in your program, you must register that signal using signal function and associate it with a signal handler.

 */

#include <iostream>
#include <csignal>		// header file for signal function
#include <unistd.h>		// header for sleep, fork, getpid, getppid

using namespace std;
// Singal Handler
// extern "C" void fun(int sig)
void signalHandler(int signum) {
	cout << "Interrupt signal (" << signum << ") received." << endl;

	// Handler tasks are
	// 1) cleanup and close up stuff here
	// 2) terminate program

	exit(signum);
}

int main() {
	// register signal SIGINT and signal handler

	signal(SIGINT, signalHandler);// catch the SIGINT and call the handler function
	// // tells, execute "signalHandler" when "SIGINT" signal is received

	int pid = fork();
	if (pid == 0) {
		cout << "Parent Process id : " << getpid() << endl;
		cout << "Child Process with parent id : " << getppid() << endl;
	}

	cout << "send a kill signal to process " << getpid()
			<< " for calling signal handler" << endl;

	while (1) {
		cout << "Going to sleep...." << endl;
		sleep(1);
	}

	return 0;
}

