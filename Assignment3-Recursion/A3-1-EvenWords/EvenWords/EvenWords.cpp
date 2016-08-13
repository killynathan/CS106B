/* File: EvenWords.cpp
 *
 * A program that uses recursion to determine which words are
 * even words.
 */
#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;

/* Function: isEvenWord(string input);
 * Usage: if (isEvenWord("tattletale")) { ... }
 * ==================================================================
 * Returns whether the given word is an "even word;" that is, whether
 * every letter in the word appears an even number of times.
 */
bool isEvenWord(string word); 

int main() {
	while (true) {
		string input = getLine("Please enter a word (enter to exit): ");
		if (input == "") break;
		if (isEvenWord(input)) cout << input << " is an even word" << endl;
		else cout << input << " is not an even word." << endl;

	}

	return 0;
}

bool isEvenWord(string word) {
	if (word == "") return true;
	char firstChar = word[0];
	word = word.substr(1);
	int index = word.find(firstChar);
	if (index != string::npos) {
		return isEvenWord(word.substr(0, index) + word.substr(index + 1));
	}
	else return false;
}

