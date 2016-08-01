/* File: RandomShuffle.cpp
 *
 * A program that uses recursion to randomly scramble the contents of
 * a string.
 */
#include <iostream>
#include <string>
#include "random.h"
#include "console.h"
#include "vector.h"
#include <math.h>
#include <ctype.h>

#include "intarray.h"
#include "buffer.h"

using namespace std;

int raiseToPower(int x, int k) {
	if (k == 1) return x;
	if (k % 2 == 0) return raiseToPower(x, k / 2) * raiseToPower(x, k / 2);
	else return raiseToPower(x, k / 2) * raiseToPower(x, k / 2) * x;
}

void swap(int & x, int & y) {
	int temp = x;
	x = y;
	y = temp;
}

void insertionSort(Vector<int> & array) {
	for (int i = 1; i < array.size(); i++) {
		int j = i;
		while (j >= 1 && array[j] < array[j - 1]) {
			swap(array[j], array[j - 1]);
			j--;
		}
		
	}
}

int main() {
	int array[4];
	if (array[0] == 1) cout << "worked";
	return 0;
}

