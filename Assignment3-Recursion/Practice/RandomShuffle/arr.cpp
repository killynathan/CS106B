#ifdef _arr_h

#include "vector.h"



template <typename valueType>
void Arr<valueType>::add(valueType element) {
	array.add(element);
}

template <typename valueType>
void Arr<valueType>::printFirst() {
	cout << array[0];
}

#endif