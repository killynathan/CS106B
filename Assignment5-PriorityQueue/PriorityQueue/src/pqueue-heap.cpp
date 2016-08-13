/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
	// TODO: Fill this in!
	count = 0;
	capacity = 10;
	arr = new string[capacity];

}

HeapPriorityQueue::~HeapPriorityQueue() {
	// TODO: Fill this in!
	delete[] arr;
}

int HeapPriorityQueue::size() {
	// TODO: Fill this in!
	return count;
}

bool HeapPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return (count) == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	count++;
	if (count == capacity) {
		expandCapacity();
	}
	arr[count] = value;
	int pos = count;
	while (pos > 1 && arr[pos / 2] > arr[pos]) {
		swap(pos / 2, pos);
		pos /= 2;
	}
}

void HeapPriorityQueue::expandCapacity() {
	capacity *= 2;
	string * newArr = new string[capacity];
	for (int i = 1; i < count; i++) {
		newArr[i] = arr[i];
	}		
	delete[] arr;
	arr = newArr;
}

string HeapPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot peek from an empty queue");
	}
	return arr[1];
}

string HeapPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot dequeue from an empty queue");
	}
	string value = arr[1];
	int pos = 1;	
	int posOfSmallerChild;
	swap(1, count);
	count--;
	posOfSmallerChild = getPosOfSmallerChild(pos);
	while (posOfSmallerChild != -1 && (arr[pos] > arr[posOfSmallerChild])) {
		swap(pos, posOfSmallerChild);
		pos = posOfSmallerChild;
		posOfSmallerChild = getPosOfSmallerChild(pos);
	}
	return value;	
}

int HeapPriorityQueue::getPosOfSmallerChild(int pos) {
	if (2 * pos > count) {
		return -1;
	}
	else if (2 * pos + 1 > count) {
		return 2 * pos;
	}
	else {
		if (arr[2 * pos] < arr[2 * pos + 1]) {
			return 2 * pos;
		}
		else {
			return 2 * pos + 1;
		}
	}
}

void HeapPriorityQueue::swap(int i, int j) {
	string temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

