/*
 * File: SierpinskiTriangle.cpp
 * ----------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter code for the Sierpinski Triangle problem
 * fron Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "graphics.h"
using namespace std;

/* Main program */

void drawFractal(int edgeLength, int order);

void drawFractalHelper(double edgeLength, int order, double x, double y);

void drawTriangle(double x, double y, double edgeLength);

int main() {
   initGraphics(700, 500);
   // Fill in the necessary code here	
	drawFractal(500, 8);
   return 0;
}

void drawFractal(int edgeLength, int order) {
	drawFractalHelper(edgeLength, order, 100, 450);
}

void drawFractalHelper(double edgeLength, int order, double x, double y) {
	if (order <= 0) return;
	else {
		drawTriangle(x, y, edgeLength);
		drawFractalHelper(edgeLength / 2, order - 1, x, y); //left
		drawFractalHelper(edgeLength / 2, order - 1, x + edgeLength / 2, y); //right
		drawFractalHelper(edgeLength / 2, order - 1, x + edgeLength / 4, (y - (edgeLength / 2) * (0.866))); //top
	}
}

void drawTriangle(double x, double y, double edgeLength) {
	GPoint p1 = drawPolarLine(x, y, edgeLength, 0);
	GPoint p2 = drawPolarLine(p1, edgeLength, 120);
	GPoint p3 = drawPolarLine(p2, edgeLength, 240);
}
