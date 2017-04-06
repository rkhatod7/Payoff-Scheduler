//Radhika Khatod, CS 130B Winter 2017

#include <iostream>
#include <fstream>
#include <sstream>
#include "payoffSchedule.h"
using namespace std;

int main(int argc, char** argv)
{

	payoffSchedule totalPayoff;
	string line;
	string arr[3];

	while(getline(cin,line))
	{
		Job job;
		int i = 0;
		stringstream currentStream(line);
		while(currentStream.good() && i < 3)
		{
			currentStream >> arr[i];
			i++;
		}
		try
		{
			job.start = stoi(arr[0]);
			job.finish   = stoi(arr[1]);
			job.payoff   = stoi(arr[2]);
		}
		catch(invalid_argument e)
		{
			printf("THE INPUTTED ARGUMENT IS INVALID\n");
			exit(1);
		}
		totalPayoff.jobs.push_back(job);

	}
	totalPayoff.myFinishSimple();
	cout << "Max Payoff: " << totalPayoff.maxPayoff() << endl;
	return 0;
}