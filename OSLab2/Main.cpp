#include <fstream>
#include <iostream>
#include <thread>
#include "point.h"

using namespace std;

//Point type to get/set all the data
Point point;

int main() {
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

	for (int i = 1; i < 257; i++) {
		res = i * i * i + 2 * i * i - 3 * i + 4;
		//add both i and res to point
	}
}

//func for thread2, write to file
//TODO: add reading of data
void quikWrite() {
	ofstream fout("output.txt");


}

//func for thread3, log everything
//TODO: add reading status of t1 and t2
void quikLog() {
	ofstream lout("log.txt");


}

//TODO: create threadsafe smart pointer (omg)