// gcc -lstdc++ -lm transform.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
using namespace std;

namespace numword_template {

constexpr const char *_version = "2019.09.27";
typedef uint64_t numnum;    // yummy numbers

// _maxstr is max size of string
constexpr size_t _maxstr = 1024;

// _maxnum is nine hundred ninty-nine quadrillion nine hundred ninty-nine trillion nine hundred ninty-nine billion nine hundred ninty-nine million nine hundred ninty-nine thousand nine hundred ninty-nine
constexpr numnum _maxnum = 999999999999999999;

static const char *errnum = "error";

static const char *_singles[] = { "zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine" };

static const char *_teens[] = { "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

static const char *_tens[] = { errnum, errnum, "twenty", "thirty", "forty",
		"fifty", "sixty", "seventy", "eighty", "ninty", };

static const char *_hundred = "hundred";

static const char *_powers[] = { errnum, "thousand", "million", "billion",
		"trillion", "quadrillion" };

static const char *_hyphen = "-";
static const char *_space = " ";

class numword {
	numnum _num = 0;
	char *_buf = nullptr;
	size_t _buflen = 0;
	bool hyphen_flag = false;

	// initialize the buffer
	void initbuf() {
		clearbuf();
		_buf = (char*) malloc(_maxstr);
		*_buf = 0;
		hyphen_flag = false;
	}

	// append space (or hyphen)
	void appendspace() {
		if (_buflen) {
			appendbuf(hyphen_flag ? _hyphen : _space);
			hyphen_flag = false;
		}
	}

	// reset the buffer
	void clearbuf() {
		if (_buf != nullptr) {
			free(_buf);
			_buf = nullptr;
		}
		_buflen = 0;
	}

	// append text to the string buffer
	void appendbuf(const char *s) {
		if (!s)
			return;
		size_t slen = strnlen(s, _maxstr);
		if (slen < 1) {
			return;
		}
		if ((slen + _buflen + 1) >= _maxstr) {
			return;
		}
		memcpy(_buf + _buflen, s, slen);
		_buflen += slen;
		_buf[_buflen] = 0;
	}

public:
	numword() :
			_num(0) {
	}

	numword(const numnum num) :
			_num(num) {
	}

	const char* version() const {
		return _version;
	}

	void setnum(const numnum num) {
		_num = num;
	}

	numnum getnum() const {
		return _num;
	}

	// assignment operator
	numnum operator =(const numnum num) {
		setnum(num);
		return getnum();
	}

	const char* words() {
		return words(_num);
	}

	// convert to words
	const char* words(const numnum num) {
		if (num > _maxnum) {
			return errnum;
		}
		initbuf();
		numnum n = num;
		if (n == 0) {
			appendbuf(_singles[n]);
			return _buf;
		}

		// powers of 1000
		if (n >= 1000) {
			for (int i = 5; i > 0; --i) {
				numnum power = (numnum) pow(1000.0, i);
				numnum _n = (n - (n % power)) / power;
				if (_n) {
					int index = i;
					numword _nw(_n);
					appendspace();
					appendbuf(_nw.words());
					appendspace();
					appendbuf(_powers[index]);
					n -= _n * power;
				}
			}
		}
		// hundreds
		if (n >= 100 && n < 1000) {
			numnum _n = (n - (n % 100)) / 100;
			numword _nw(_n);
			appendspace();
			appendbuf(_nw.words());
			appendspace();
			appendbuf(_hundred);
			n -= _n * 100;
		}
		// tens
		if (n >= 20 && n < 100) {
			numnum _n = (n - (n % 10)) / 10;
			appendspace();
			appendbuf(_tens[_n]);
			n -= _n * 10;
			hyphen_flag = true;
		}
		// teens
		if (n >= 10 && n < 20) {
			appendspace();
			appendbuf(_teens[n - 10]);
			n = 0;
		}
		// singles
		if (n > 0 && n < 10) {
			appendspace();
			appendbuf(_singles[n]);
		}
		return _buf;
	}

	const char* operator ()(const numnum num) {
		return words(num);
	}

	// destructor
	~numword() {
		clearbuf();
	}
};

}

template<typename T>
class Template {
	T val = 0;
	Template() {
	}
public:
	Template(T n) :
			val(n) {
	}
	T operator()(T y) {
		val += y;
		return val;
	}
};

template<typename T>
void display_vector(vector<T> &vect) {
	if (!vect.size())
		return;
	for (T element : vect) {
		cout << element << " ";
	}
	cout << endl;
}

template<typename T>
void display(const T &vect) {
	if (!vect.size())
		return;
	bool first = true;
	for (auto element : vect) {
		if (first)
			first = false;
		else
			cout << ", ";
		cout << element;
	}
	cout << endl;
}

int main() {
	Template<int> t_obj(7);
	cout << t_obj(7) << endl;

	vector<int> int_vector = { 1, 2, 3, 4, 5 };
	display_vector(int_vector);

	vector<int> copied_vector(int_vector.size());
	transform(int_vector.begin(), int_vector.end(), copied_vector.begin(),
			t_obj);

	display_vector(copied_vector);

	const vector<uint64_t> cont_int_vector = { 1, 2, 3, 4, 5, 60, 72, 847, 9001,
			10002052 };
	display(cont_int_vector);

	numword_template::numword nw;
	vector < string > words(cont_int_vector.size());
	transform(cont_int_vector.begin(), cont_int_vector.end(), words.begin(),
			nw);
	display_vector (words);

	vector<long> long_vector_1 = { 26, 52, 79, 114, 183 };
	vector<long> long_vector_2 = { 1, 2, 3, 4, 5 };
	vector<long> long_vector_3(long_vector_1.size(), 0);
	display_vector(long_vector_1);
	display_vector(long_vector_2);
	display_vector(long_vector_3);
	cout << endl;

	plus<long> f;
	transform(long_vector_1.begin(), long_vector_1.end(), long_vector_2.begin(),
			long_vector_3.begin(), f);
	display_vector(long_vector_3);

	string str = "this is a string";
	cout << str << endl;

	string copied_string(str.size(), '.');
	transform(str.begin(), str.end(), copied_string.begin(), ::toupper);

	cout << copied_string << endl;

	return 0;
}
