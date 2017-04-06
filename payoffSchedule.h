//Radhika Khatod, CS 130B Winter 2017

/*
#include <vector>
using namespace std;

#ifndef PAYOFF_SCHED_H
#define PAYOFF_SCHED_H

typedef struct Job Job;

struct Job {
  int start, finish, payoff;
};


class payoffSchedule {

public:
	
	
	void printJobs();
	vector<Job> jobs;
	int maxPayoff(vector<Job> arr, int n);
	int binarySearch(vector<Job> jobs, int index);

private:	

	int payout;

};
#endif

*/
#include <vector>

#ifndef PAYOFFSCHEDULE_H
#define PAYOFFSCHEDULE_H
using namespace std;


struct Job {
  int start, finish, payoff;
   Job& operator=(const Job &j){
  	this->start = j.start;
  	this->finish = j.finish;
  	this->payoff = j.payoff;
  	return *this;
  }
};

class payoffSchedule {

public:
	void printJobs();

	int maxVal(int a, int b);

	int latestNonConflict(int index);

	void myFinishSimple();

	void myFinishSort(int start, int finish);

	int partition(int start, int finish);

	void swap(int index1, int index2);

	int maxPayoff();

	vector<Job> jobs;
	int optimal[100000];
	//vector < vector < Job > > optimal;
private:	

	int payout;

};

#endif
