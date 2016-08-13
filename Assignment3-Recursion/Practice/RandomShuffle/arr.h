#ifndef _arr_h
#define _arr_h

#include "vector.h"

template <typename valueType>
class Arr {
public: 

	void add(valueType element);

	void printFirst();

private:
	Vector<valueType> array;
};
#include "arr.cpp"

#endif