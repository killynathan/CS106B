#include <string>
#include <iostream>
#include "part1.h"

using namespace std;

bool isPerfect(int num) {
	//get divisors add to count
	//loop through from 1 to to num/2
	//if num is divisible by i, add i to count
	int count = getSumOfDivisors(num);

	//check if count is eqaul to num
	if (count == num) {
		return true;
	}
	else {
		return false;
	}
}

int getSumOfDivisors(int num) {
	int count = 0;
	for (int i = 1; i <= (num / 2); i++) {
		if (num % i == 0) {
			count += i;
		}
	}
	return count;
}