#include <iostream>
#include "buffer.h"
#include <string>
using namespace std;

const int INITIAL_CAPACITY = 10;

EditorBuffer::EditorBuffer() {
	capacity = INITIAL_CAPACITY;
	array = new char[capacity];
	stackOneEnd = 0;
	stackTwoStart = capacity - 1;
	copiedText = "";
}

EditorBuffer::~EditorBuffer() {
	delete[] array;
}

void EditorBuffer::insertCharacter(char ch) {
	if (stackOneEnd == stackTwoStart) expandCapacity();

	array[stackOneEnd] = ch;
	stackOneEnd++;
}

void EditorBuffer::deleteCharacter() {
	if (stackOneEnd != 0) 
		stackOneEnd--;
}

void EditorBuffer::deleteWord() {
	while (stackOneEnd != 0) {
		if (array[stackOneEnd - 1] == ' ')
			break;
		else
			stackOneEnd--;
	}
}

void EditorBuffer::moveCursorBackward() {
	if (stackOneEnd != 0) {
		array[stackTwoStart] = array[stackOneEnd - 1];
		stackOneEnd--;
		stackTwoStart--;
	}
}

void EditorBuffer::moveCursorBackwardOneWord() {
	while (stackOneEnd != 0) {
		if (array[stackOneEnd - 1] == ' ')
			break;
		else
			moveCursorBackward();
	}
}

void EditorBuffer::moveCursorForward() {
	if (stackTwoStart != capacity - 1) {
		array[stackOneEnd] = array[stackTwoStart + 1];
		stackOneEnd++;
		stackTwoStart++;
	}
}

void EditorBuffer::moveCursorForwardOneWord() {
	while (stackTwoStart != capacity - 1) {
		if (array[stackTwoStart + 1] == ' ')
			break;
		else
			moveCursorForward();
	}
}

void EditorBuffer::moveCursorToStart() {
	while (stackOneEnd != 0) {
		array[stackTwoStart] = array[stackOneEnd - 1];
		stackTwoStart--;
		stackOneEnd--;
	}
}

void EditorBuffer::moveCursorToEnd() {
	while (stackTwoStart != capacity - 1) {
		array[stackOneEnd] = array[stackTwoStart + 1];
		stackOneEnd++;
		stackTwoStart++;
	}
}

void EditorBuffer::copy(int count) {
	copiedText = "";
	for (int i = 0; i < count; i++) {
		if (stackTwoStart + i == capacity - 1) break;
		copiedText += array[stackTwoStart + 1 + i];
	}
}

void EditorBuffer::paste() {
	for (int i = 0; i < copiedText.length(); i++) {
		insertCharacter(copiedText[i]);
	}
}

void EditorBuffer::showContent() {
	for (int i = 0; i < stackOneEnd; i++) {
		cout << array[i] << "";
	}
	cout << "|";
	for (int i = stackTwoStart + 1; i < capacity; i++) {
		cout << array[i] << "";
	}
	cout << endl;
}

void EditorBuffer::expandCapacity() {
	capacity *= 2;
	char *temp = new char[capacity];
	
	for (int i = 0; i < stackOneEnd; i++) {
		temp[i] = array[i];
	}

	for (int i = 0; i < (capacity / 2 - stackTwoStart - 1); i++) {
		temp[capacity - 1 - i] = array[capacity / 2 - 1 - i];
	}

	stackTwoStart = capacity - (capacity / 2 - stackTwoStart);	

	delete[] array;
	array = temp;
}

