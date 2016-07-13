#include <string>
#include <iostream>
#include "random.h"

#include "part2.h"


using namespace std;

double getVotingAccuracy(int numTries, int numVotersTotal, double spread, double error) {
	int numVoters1 = int(numVotersTotal * (0.5 + spread / 100 / 2));
	int numVoters2 = int(numVotersTotal * (0.5 - spread / 100 / 2));

	return runSimulation(numTries, numVoters1, numVoters2, error);
}

double getVotes(int numVoters, double error) {
	int numVotes = 0;
	for (int i = 0; i < numVoters; i++) {
		if (randomInteger(1, 100) > error) {
			numVotes++;
		}
	}
	return numVotes;
}

double runSimulation(int numTries, int numVoters1, int numVoters2, double error) {
	int numSuccesses = 0;
	for (int i = 0; i < numTries; i++) {
		int numVotes1 = getVotes(numVoters1, error);
		int numVotes2 = getVotes(numVoters2, error);
		int temp = numVotes2;
		numVotes2 += (numVoters1 - numVotes1);
		numVotes1 += (numVoters2 - temp);

		if (numVotes1 > numVotes2) {
			numSuccesses++;
		}
	}
	return (double(numSuccesses) / numTries) * 100;
}