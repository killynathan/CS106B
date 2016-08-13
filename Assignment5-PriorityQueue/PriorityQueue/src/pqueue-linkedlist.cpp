/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	// TODO: Fill this in!
	root = NULL;
	count = 0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	// TODO: Fill this in!
	clear();
}

void LinkedListPriorityQueue::clear() {
	Cell * i = root;
	while (i != NULL) {
		Cell * next = i->next;
		delete i;
		i = next;
	}
}

int LinkedListPriorityQueue::size() {
	// TODO: Fill this in!
	return count;
}

bool LinkedListPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return count == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	Cell * i = root;
	Cell * j = NULL;
	while (i != NULL && value > i->value) {
		j = i;
		i = i->next;
	}
	Cell * newCell = new Cell;
	newCell->value = value;
	newCell->next = i;
	if (j == NULL) {
		root = newCell;
	}
	else {
		j->next = newCell;
	}
	count++;
}

string LinkedListPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot peek from empty queue");
	}
	else {
		return root->value;
	}
}

string LinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot dequeue from empty queue");
	}
	else {
		string value = root->value;
		Cell * temp = root;
		root = root->next;
		delete temp;
		count--;
		return value;
	}
}

