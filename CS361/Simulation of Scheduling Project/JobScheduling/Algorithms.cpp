#include "Algorithms.h"

void fifo(vector<job>& jobs, int maxDuration)
{
	int currentTime = 0;
	int completed = 0;
	int nextJob = 0;
	queue<job*> readyQueue;

	while (completed < jobs.size() && currentTime < maxDuration) {
		while (nextJob < jobs.size() && jobs[nextJob].arrivalTime <= currentTime) {
			readyQueue.push(&jobs[nextJob]);
			nextJob++;
		}
    if (!readyQueue.empty()) {
            job* current = readyQueue.front();
            readyQueue.pop();

            if (current->startTime == -1) {
                current->startTime = currentTime;
            }

            currentTime += current->remainingTime;
            current->endTime = currentTime;
            current->remainingTime = 0;
            completed++;
        }
    else 
    {
        currentTime++;
        }
	}
}

void rr(vector<job>& jobs, int maxDuration, int timeQuantum) {
    queue<job*> readyQueue;
    int currentTime = 0;
    int completed = 0;
    int nextJob = 0;

    while (completed < jobs.size() && currentTime < maxDuration) {
        while (nextJob < jobs.size() && jobs[nextJob].arrivalTime <= currentTime) {
            readyQueue.push(&jobs[nextJob]);
            nextJob++;
        }
        if (!readyQueue.empty()) {
            job* current = readyQueue.front();
            readyQueue.pop();

            if (current->startTime == -1) {
                current->startTime = currentTime;
            }

            int executeTime;
            if (current->remainingTime < timeQuantum) {
                executeTime = current->remainingTime;
            }
            else {
                executeTime = timeQuantum;
            }
            current->remainingTime -= executeTime;
            currentTime += executeTime;
            while (nextJob < jobs.size() && jobs[nextJob].arrivalTime <= currentTime) {
                readyQueue.push(&jobs[nextJob]);
                nextJob++;
            }

            if (current->remainingTime > 0) {
                readyQueue.push(current);
            }
            else {
                current->endTime = currentTime;
                completed++;
            }
        }
        else {
            currentTime++;
        }
    }
}


void mlf(vector<job>& jobs, int maxDuration)
{
    const int queueNum = 3;
    queue<job*> readyQueues[queueNum];
    int currentTime = 0;
    int completed = 0;
    vector<int> timeQuantums = {1, 2, 4};
    int nextJob = 0;
    int executeTime;

    while (completed < jobs.size() && currentTime < maxDuration) {
        while (nextJob < jobs.size() && jobs[nextJob].arrivalTime <= currentTime) {
            readyQueues[0].push(&jobs[nextJob]);
            nextJob++;
        }
        int currentQueue = 0;
        while (currentQueue < queueNum && readyQueues[currentQueue].empty()) {
            currentQueue++;
        }
        if (currentQueue < queueNum) {
            job* current = readyQueues[currentQueue].front();
            readyQueues[currentQueue].pop();
            if (current->startTime == -1) {
                current->startTime = currentTime;
            }
            if (current->remainingTime < timeQuantums[currentQueue]) {
                executeTime = current->remainingTime;
            }
            else {
                executeTime = timeQuantums[currentQueue];
            }
            current->remainingTime -= executeTime;
            currentTime += executeTime;

            while (nextJob < jobs.size() && jobs[nextJob].arrivalTime <= currentTime) {
                readyQueues[0].push(&jobs[nextJob]);
                nextJob++;
            }
            if (current->remainingTime > 0) {
                int nextQueue;
                if (currentQueue + 1 < queueNum) {
                    nextQueue = currentQueue + 1;
                }
                else {
                    nextQueue = queueNum - 1;
                }
                readyQueues[nextQueue].push(current);
            }
            else {
                current->endTime = currentTime;
                completed++;
            }
        }
        else {
            currentTime++;
        }
    }
}

void DisplayResults(vector<job>& jobs)
{
    double totalTurnaround = 0;
    int completedJobs = 0;
    cout << " results" << endl;
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i].endTime != -1) {
            totalTurnaround += jobs[i].endTime - jobs[i].arrivalTime;
            completedJobs++;
        }
    }
    if (completedJobs > 0) {
        cout << "completed jobs: " << completedJobs << endl;
        cout << "average turnaround time: " << totalTurnaround / completedJobs << endl;
    }
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i].endTime != -1) {
            cout << "ID: " << jobs[i].id << endl;
            cout << "Arrival Time: " << jobs[i].arrivalTime << endl;
            cout << "Cpu Time: " << jobs[i].cpuTime << endl;
            cout << "End Time: " << jobs[i].endTime << endl;
            cout << "Start Time: " << jobs[i].startTime << endl;
        }
    }



}
