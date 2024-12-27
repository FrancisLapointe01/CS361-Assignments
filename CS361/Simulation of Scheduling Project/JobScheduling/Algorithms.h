#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct job {
	int id;
	int arrivalTime;
	int remainingTime;
	int cpuTime;
	int startTime;
	int endTime;
};
void fifo(vector<job>&, int);
void rr(vector<job>&, int, int);
void mlf(vector<job>&, int);
void DisplayResults(vector<job>&);