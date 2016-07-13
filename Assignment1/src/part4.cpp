#include "part4.h"

#include <string>
#include <iostream>
#include <fstream>
#include "vector.h"
using namespace std;

void makeHistogram(ifstream& in) {
	string line;
	Vector<int> tally(10, 0);

	while (true) {
		int score;
		in >> score;
		if (in.fail()) break;
		int tensDigit = score / 10;
        tally[tensDigit]++;
	}

    for (int i = 0; i < tally.size(); i++) {
        cout << i*10 << "-" << i*10 + 9 << ": ";
        for (int j = 0; j < tally[i]; j++) {
            cout << "x";
        }
        cout << "" << endl;
    }
}
