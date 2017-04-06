//Radhika Khatod, CS 130B Winter 2017


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "payoffSchedule.h"
using namespace std;

// HELPER FUNCTIONS //

void payoffSchedule::myFinishSimple(){
	myFinishSort(0,jobs.size());
}

void payoffSchedule::myFinishSort(int start, int finish){
	if(start < finish){
		int x = partition(start,finish);
		myFinishSort(start,x);
		myFinishSort(x+1,finish);
	}
}
int payoffSchedule::maxVal(int a, int b){
	if(a > b) 
		return a;
	return b;
}

int payoffSchedule::partition(int start, int finish){
	int currentIndex = start;
	int curFinish = jobs[currentIndex].finish;
	int i = currentIndex;
	for(int j = currentIndex+1; j < finish; j++){
		if(jobs[j].finish <= curFinish){
			i++;
			swap(i,j);
		}
	}
	if(jobs[i].finish < jobs[currentIndex].finish && i > currentIndex)
		swap(currentIndex,i);
	return i;
}

void payoffSchedule::swap(int index1, int index2){
	Job temp = jobs[index1];
	jobs[index1] = jobs[index2];
	jobs[index2] = temp;
}



int payoffSchedule::latestNonConflict(int index){
	if(index == 0){ 
		return 0;
	}
	int max = index-1;
	int min = 0;
	int i;
	int startTime = jobs[index].start;
	while(min <= max){
		int mid = (min+max)/2;
		if(jobs[mid].finish <= startTime){
			if(jobs[mid+1].finish <= startTime)
				min = mid+1;
			else
				return mid;
		}
		else
			max = mid-1;
	}
	return -1;
}

// MAIN FUNCTION //

int payoffSchedule::maxPayoff(){
	myFinishSimple();
	int jobSize = jobs.size();
	if(jobSize == 1){
		return jobs[0].payoff;
	}
	//printf("what is this: %d\n", optimal[0][0].payoff);
	//optimal.at(0).at(0).payoff = jobs[0].payoff;
	optimal[0] = jobs[0].payoff;

	for(int i = 1; i < jobSize; i++){
		int currentNon = latestNonConflict(i); 
		int currentProfit = jobs[i].payoff;
		int currentJob = i;
		int currentStart = jobs[i].start;
		int currentFinish = jobs[i].finish;
		if(currentNon != -1){
			currentProfit += optimal[currentNon];
		}
		//optimal[i] = max(currentProfit, optimal[i-1]);
		/*
		if (currentProfit > optimal[i-1][i-1].payoff){
			printf("current profit in here is: %d\n", currentProfit);
			optimal[i].push_back(jobs[i]);
			for(int i = 0; i <= optimal[currentNon].size(); i++){
				optimal[i].push_back(optimal[currentNon][i]);
			}
		}
			// you need to add the jobs from the index optimal[currentNon] and jobs[i]
		else{
			for(int i = 0; i <= optimal[i-1].size(); i++){
				optimal[i].push_back(optimal[i-1][i-1]);
			}
			//loop through
			// you need to make optimal[i] = all the jobs at index optimal[i-1]
		}
*/
	}

	return optimal[jobSize-1];
}


void payoffSchedule::printJobs(){
	for(int i = 0; i < jobs.size(); i++){
		printf("Job %d: start=%d finish=%d pay=%d\n",i,jobs[i].start,jobs[i].finish,jobs[i].payoff);
	}
}
