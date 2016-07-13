#include <iostream>
#include "console.h"
#include "vector.h"  // for Vector
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

void countLetters(string fileName) {
    Vector<int> letterCount(26, 0);
    ifstream in;
    in.open(fileName);
    if (in.fail()) {
        cout << "cannot open file";
        return;
    }
    char letter;
    while (true) {
        in >> letter;
        if (in.fail()) break;
        letter = tolower(letter);
        if (isalpha(letter) != 0) {
            int pos = letter - 'a';
            letterCount.set(pos, letterCount.get(pos) + 1);
        }
    }

    for (int i = 0; i < letterCount.size(); i++) {
        char ch = (char)('a' + i);
        cout << ch << ": " << letterCount.get(i) << endl;
    }
}


int main() {

    countLetters("words.txt");
    return 0;
}
