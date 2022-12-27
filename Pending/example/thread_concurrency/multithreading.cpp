// g++ -pthread  multithreading.cpp   		// For compiling
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
#define NUM_THREADS     10

struct thread {
	int thread_id;
	char *message;
};
void* Run(void *threadarg) {
	struct thread *data = (struct thread*) threadarg;
	cout << "Thread ID: " << data->thread_id << " Message: " << data->message
			<< endl;
	pthread_exit (NULL);
}

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,  void *(*start_routine) (void *), void *arg);
// The pthread_create() function is used to create a new thread, with attributes specified by attr, within a process. If attr is NULL, the default attributes are used. If the attributes specified by attr are modified later, the thread's attributes are not affected. Upon successful completion, pthread_create() stores the ID of the created thread in the location referenced by thread.
// pthread_t is a type similar to int and it's created when you define it, not when you call pthread_create

int main() {
	pthread_t threads[NUM_THREADS];				// array of pthread_t objects
	struct thread thread_data[NUM_THREADS];		// array of thread data objects
	int result, counter;
	for (counter = 0; counter < NUM_THREADS; counter++) {	// creating threads
		cout << "Creating Thread Number " << counter << endl;
		thread_data[counter].thread_id = counter;
		thread_data[counter].message = (char*) "This is message";
		result = pthread_create(&threads[counter], NULL, Run,
				(void*) &thread_data[counter]);	// creating threads
		if (result) {
			cout << "Error:unable to create thread " << result << endl;
			exit(-1);
		}
	}
	pthread_exit (NULL);// The pthread_exit() function terminates the calling thread and makes the value value_ptr available to any successful join with the terminating thread
}

