#include "part3.h"
#include <string>

using namespace std;

void capitalizeFirstLetter(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
}

void convertLettersToDigits(string& str) {
	for (int i = 1; i < str.length(); i++) {
		switch (str[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'h':
		case 'w':
		case 'y':
			str[i] = '0';
			break;
		case 'b':
		case 'f':
		case 'p':
		case 'v':
			str[i] = '1';
			break;
		case 'c':
		case 'g':
		case 'j':
		case 'k':
		case 'q':
		case 's':
		case 'x':
		case 'z':
			str[i] = '2';
			break;
		case 'd':
		case 't':
			str[i] = '3';
			break;
		case 'm':
		case 'n':
			str[i] = '5';
			break;
		case 'l':
			str[i] = '4';
			break;
		case 'r':
			str[i] = '6';
			break;
		default:
			break;
		}
		
	}
}

void removeConsecutive(string& str) {
	char current;
	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			current = str[i];
		}
		else {
			if (str[i] == current) {
				str.erase(i, 1);
				i--;		
			} else {
				current = str[i];
			}
		}
	}
}

void removeZeros(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') {
			str.erase(i, 1);
			i--;
		}
	}
}

void makeLengthFour(string& str) {
	str = str.substr(0, 4);
	while (str.length() < 4) {
		str.append("0");
	}
}

void getSoundexCode(string& str) {
	capitalizeFirstLetter(str);
	convertLettersToDigits(str);
	removeConsecutive(str);
	removeZeros(str);
	makeLengthFour(str);
}