// gcc -lstdc++ -pthread -lm shared_pointer.cc
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

struct Base {
	Base() {
		cout << "Base::Base()" << endl;
	}
	// Note: non-virtual destructor is OK here
	~Base() {
		cout << "Base::~Base()" << endl;
	}
};

struct Derived: public Base {
	Derived() {
		cout << "Derived::Derived()" << endl;
	}
	~Derived() {
		cout << "Derived::~Derived()" << endl;
	}
};

void thr(shared_ptr<Base> p) {
	this_thread::sleep_for(chrono::seconds(1));
	shared_ptr<Base> lp = p; // thread-safe, even though the
							 // shared use_count is incremented
	{
		static mutex io_mutex;
		lock_guard < mutex > lk(io_mutex);
		cout << "local pointer in a thread:" << endl << "  lp.get() = "
				<< lp.get() << ", lp.use_count() = " << lp.use_count() << endl;
	}
}

int main() {
	shared_ptr<Base> p = make_shared<Derived>();

	cout << "Created a shared Derived (as a pointer to Base)" << endl
			<< " p.get() = " << p.get() << ", p.use_count() = " << p.use_count()
			<< endl;
	thread t1(thr, p), t2(thr, p), t3(thr, p);
	p.reset(); // release ownership from main
	cout << "Shared ownership between 3 threads and released" << endl
			<< "ownership from main:" << endl << "  p.get() = " << p.get()
			<< ", p.use_count() = " << p.use_count() << endl;
	t1.join();
	t2.join();
	t3.join();
	cout << "All threads completed, the last one deleted Derived" << endl;
	return 0;
}
