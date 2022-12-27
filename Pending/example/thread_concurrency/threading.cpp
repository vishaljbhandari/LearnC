// g++ -pthread Sthreading.cpp
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;
#define NUM_THREADS     5

void* wait(void *t) {
	long tid = (long) t;
	sleep(1);
	cout << "Sleeping in thread with id : " << tid << "  ...exiting " << endl;
	pthread_exit (NULL);
}

int main() {
	int result, counter;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	// Initialize and set thread joinable
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (counter = 0; counter < NUM_THREADS; counter++) {
		cout << "main() : creating thread " << counter << endl;
		result = pthread_create(&threads[counter], &attr, wait,
				(void*) counter);
		if (result) {
			cout << "Error:unable to create thread " << result << endl;
			exit(-1);
		}
	}

	// Free attribute and wait for the other threads
	pthread_attr_destroy(&attr);

	for (counter = 0; counter < NUM_THREADS; counter++) {
		result = pthread_join(threads[counter], &status);
		if (result) {
			cout << "Error:unable to join " << result << endl;
			exit(-1);
		}
		cout << "Main: completed thread id " << counter
				<< " exiting with status " << status << endl;
	}
	cout << "Main: program exiting." << endl;
	pthread_exit (NULL);
	return 0;
}

