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
#include "vector.h"

#include "intarray.h"
#include "buffer.h"
#include "arr.h"

using namespace std;

struct cell {
	int value;
	cell * left;
	cell * right;
};

void addCell(cell * & c, int value) {
	if (c == NULL) {
		c = new cell;
		c->left = c->right = NULL;
		c->value = value;
	}
	else if (c->value == value) {
		return;
	}
	else if (value < c->value) {
		addCell(c->left, value);
	}
	else {
		addCell(c->right, value);
	}	
}

void printTree(cell * c) {
	if (c != NULL) {
		printTree(c->left);
		cout << c->value << endl;
		printTree(c->right);
	}
}

int getTreeHeight(cell * c) {
	if (c == NULL) {
		return 0;
	}
	int left = getTreeHeight(c->left);
	int right = getTreeHeight(c->right);
 
	if (left > right) return 1 + left;
	else return 1 + right;
}

cell * findCommonAncestor(cell * c, int c1, int c2) {
	if (c == NULL) {
		return NULL;
	}
	if ((c->value >= c1 && c->value <= c2) || (c->value <= c1 && c->value >= c2)) {
		return c;
	}
	else if (c->value > c1 && c->value > c2) {
		findCommonAncestor(c->left, c1, c2);
	}
	else if (c->value < c1 && c->value < c2) {
		findCommonAncestor(c->right, c1, c2);
	}
}

bool isBalanced(cell * c) {
	return ((getTreeHeight(c->left) - getTreeHeight(c->right) <= 1) && (getTreeHeight(c->left) - getTreeHeight(c->right) >= -1));	
}

/*
void removeCell(cell * & c, int value) {
	if (c == NULL) {
		cout << "Cell not found" << endl;
		return;
	}
	else if (c->value == value) {
		if (c->left == NULL) {
			cell * temp = c;
			c = c->right;
			delete temp;
		}
		else if (c->right == NULL) {
			cell * temp = c;
			c = c->right;
			delete temp;
		}
	}
	
}
*/

int main() {
	cell * root = new cell;
	root->value = 50;
	root->left = root->right = NULL;
	addCell(root, 20);
	addCell(root, 70);
	addCell(root, 1);
	addCell(root, 35);
	addCell(root, 60);
	addCell(root, 100);
	addCell(root, 120);
	addCell(root, 80);
	addCell(root, 55);
	addCell(root, 65);
	printTree(root);
	cout << isBalanced(root);
	return 0;
}