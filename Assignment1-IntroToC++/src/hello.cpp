#include <iostream>
#include "vector.h"  // for Vector
#include "console.h"
#include <fstream>
#include <string>
#include "part1.h"
#include "part2.h"
#include "part3.h"
#include "part4.h"
using namespace std;

int main() {
    cout << "testing for part 1: finding perfect numbers" << endl;
    for (int i = 1; i <= 10000; i++) {
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }

    cout << "testing for part 2: testing voting machine accuracy" << endl;
    cout << getVotingAccuracy(500, 20000, 1, 10) << endl;

    cout << "testing for part 3: soundex code generator" << endl;
    string test = "Zelenski";
    getSoundexCode(test);
    cout << test << endl;

    cout << "testing for part 4: histogram creator" << endl;
    ifstream in("scores.txt");
    makeHistogram(in);



    cin.get();

    return 0;
}
