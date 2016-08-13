/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	// TODO: Fill this in!
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}

int VectorPriorityQueue::size() {
	// TODO: Fill this in!
	return arr.size();
}

bool VectorPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return arr.size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	arr.add(value);
}

string VectorPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Connot peek from an empty queue.");
	}
	else {
		return arr[getIndexOfSmallestElement()];
	}
}

string VectorPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot dequeue from an empty queue.");
	}
	else {
		int indexOfSmallest = getIndexOfSmallestElement();
		string smallest = arr[indexOfSmallest];
		arr.removeAt(indexOfSmallest);
		return smallest;
	}
}

int VectorPriorityQueue::getIndexOfSmallestElement() {
	int indexOfSmallest = 0;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] < arr[indexOfSmallest]) {
			indexOfSmallest = i;
		}
	}
	return indexOfSmallest;
}

