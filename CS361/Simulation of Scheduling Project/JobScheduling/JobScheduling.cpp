// JobScheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algorithms.h"
int main()
{
	vector<job> jobs;
	int maxDurations = 2000;
	for (int i = 0; i < 5; i++) {
		job j;
		j.id = i;
		j.arrivalTime = i * 2;
		j.cpuTime = 10;
		j.remainingTime = j.cpuTime;
		j.startTime = -1;
		j.endTime = -1;
		jobs.push_back(j);
	}

	int algorithmselected;
	cout << "Pick an algorithm" << endl;
	cout << "1. FIFO" << endl;
	cout << "2. RR" << endl;
	cout << "3. MLF" << endl;
	cin >> algorithmselected;
	if (algorithmselected == 1) {
		cout << "FIFO";
		fifo(jobs, maxDurations);
		DisplayResults(jobs);
	}
	if (algorithmselected == 2) {
		cout << "RR";
		rr(jobs, maxDurations, 1);
		DisplayResults(jobs);
	}
	if (algorithmselected == 3) {
		cout << "MLF";
		mlf(jobs, maxDurations);
		DisplayResults(jobs);
	}
	else if (algorithmselected >= 4) {
		cout << "Not a valid option " << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
