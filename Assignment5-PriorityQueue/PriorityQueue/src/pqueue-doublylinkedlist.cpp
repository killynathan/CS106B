/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	// TODO: Fill this in!
	count = 0;
	root = NULL;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	// TODO: Fill this in!
	clear();
}

void DoublyLinkedListPriorityQueue::clear() {
	Cell * i = root;
	while (i != NULL) {
		Cell * next = i->next;
		delete i;
		i = next;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	// TODO: Fill this in!
	return count;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return count == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	Cell * newCell = new Cell;
	newCell->value = value;
	newCell->next = root;
	newCell->prev = NULL;
	if (root != NULL) {
		root->prev = newCell;
	}	
	root = newCell;
	count++;
}

string DoublyLinkedListPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot dequeue from an empty queue");
	}
	else {
		Cell * smallest = getSmallestCell();
		return smallest->value;
	}
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Cannot dequeue from an empty queue");
	}
	else {
		Cell * smallest = getSmallestCell();
		string value = smallest->value;
		if (smallest->prev != NULL) {
			smallest->prev->next = smallest->next;
		}
		if (smallest->next != NULL) {
			smallest->next->prev = smallest->prev;
		}
		if (smallest == root) {
			root = smallest->next;
		}
		delete smallest;
		count--;
		return value;
	}
}


DoublyLinkedListPriorityQueue::Cell * DoublyLinkedListPriorityQueue::getSmallestCell() {
	Cell * smallest = root;
	for (Cell * i = root; i != NULL; i = i->next) {
		if (i->value < smallest->value) {
			smallest = i;
		}
	}
	return smallest;
}
