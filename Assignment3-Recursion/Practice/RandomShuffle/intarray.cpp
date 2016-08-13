#include "intarray.h"
#include "error.h"

IntArray::IntArray(int n) {
	array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i] = 0;
	}
	length = n;
}

IntArray::IntArray(const IntArray & arr) {
	length = arr.length;
	array = new int[length];
	for (int i = 0; i < length; i++) {
		array[i] = arr.array[i];
	}
}

IntArray::~IntArray() {
	delete[] array;
}

int IntArray::size() {
	return length;
}

int IntArray::get(int k) {
	if (k < 0 || k >= length) error("out of bounds");
	else return array[k];
}

void IntArray::put(int k, int value) {
	if (k < 0 || k >= length) error("out of bounds");
	else array[k] = value;
}

int & IntArray::operator[](int k) {
	if (k < 0 || k >= length) error("out of bounds");
	else {
		return array[k];
	}
}

IntArray & IntArray::operator=(const IntArray & rhs) {
	if (this != &rhs) {
		delete[] array;

		length = rhs.length;
		array = new int[length];

		for (int i = 0; i < length; i++) {
			array[i] = rhs.array[i];
		}
	}
	return *this;
}



