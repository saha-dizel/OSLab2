#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include "point.h"

using namespace std;

//Point type to get/set all the data
Point point;

//Mutex time!
mutex mtx;

//unique lock so mutex can be watched
unique_lock< mutex > lck(mtx, defer_lock);

int main(void) {
	thread t1(quikMafs);
	thread t2(quikWrite);
	thread t3(quikLog);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}

//func for thread1, calc everything
//TODO: add writing of data
void quikMafs() {
	int res = 0;
	int i = 1;

	for (;;) {
		lck.lock();
		res = i * i * i + 2 * i * i - 3 * i + 4;

		//add both i and res to point

		if (i = 256) {
			lck.unlock();
			break;
		}
		else {
			i++;
			lck.unlock();
		}
	}
}

//func for thread2, write to file
//TODO: add reading of data
void quikWrite() {
	lck.lock();

	ofstream fout("output.txt");

	//fout result from point to file

	//we might do the following to guarantee quikMafs to start first
	//if this locks mutex before quikMafs, that means that Point is empty
	//so add check if point is null, then unlock mutex
	//after this quikMafs catches mutex, so we are guaranteed, that it starts working first

	lck.unlock();
}

//func for thread3, log everything
//TODO: add reading status of t1 and t2
void quikLog() {
	ofstream lout("log.txt");

	while (true){
		if (lck.owns_lock())
			//TODO: output time
			lout << "Hello!" << endl;
	}
}

//TODO: create threadsafe smart pointer (omg)
//TODO: richter (to read through)