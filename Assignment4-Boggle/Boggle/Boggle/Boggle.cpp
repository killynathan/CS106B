/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */
 
#include <iostream>
#include "gboggle.h"
#include "graphics.h"
#include "grid.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
#include <stdlib.h>
#include <string>
#include "strlib.h"
#include <ctype.h>
#include "vector.h"
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;

const string STANDARD_CUBES[16]  = {
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
   "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
   "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
   "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

struct Point {int x; int y;};

/* Function prototypes */

void welcome();
void promptInstructions();
void giveInstructions();
void setupBoard(Grid<char> & gameBoard);
void setupBoardManually(Grid<char> & gameBoard);
void setupBoardRandomly(Grid<char> & gameBoard);
void randomizeCubes(Vector<string> & cubes);
void displayAndSetCubes(Grid<char> & gameBoard, string boardConfig);
void playerTurn(Grid<char> & gameBoard, Lexicon & lex);
bool isWord(string word, Lexicon & lexi);
bool onBoard(Grid<char> & gameBoard, string word);
bool wordHere(Grid<char> & gameBoard, Grid<bool> & visited, string word, string curr, int x, int y, int count);
void clearBoardOfHighlights(Grid<char> & gameBoard);
void computerTurn(Grid<char> & gameBoard, Lexicon & lex);
void displayWordsStartingHere(Grid<char> & gameBoard, Grid<bool> & visited, Lexicon & lex, Lexicon & usedWords, string current, int x, int y);

/* Main program */

int main() {
	Grid<char> gameBoard;
	Lexicon lex("EnglishWords.dat");

    initGraphics(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
	cout << lex.containsPrefix("rew");
    welcome();

    promptInstructions();

	setupBoard(gameBoard);

	playerTurn(gameBoard, lex);
   
	computerTurn(gameBoard, lex);

    return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
   cout << "Welcome!  You're about to play an intense game ";
   cout << "of mind-numbing Boggle.  The good news is that ";
   cout << "you might improve your vocabulary a bit.  The ";
   cout << "bad news is that you're probably going to lose ";
   cout << "miserably to this little dictionary-toting hunk ";
   cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

void promptInstructions() {
	string wantInstructions = getLine("Do you want instructions (y/n)? ");
    if (wantInstructions == "y") giveInstructions();
	cout << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
   cout << endl;
   cout << "The boggle board is a grid onto which I ";
   cout << "I will randomly distribute cubes. These ";
   cout << "6-sided cubes have letters rather than ";
   cout << "numbers on the faces, creating a grid of ";
   cout << "letters on which you try to form words. ";
   cout << "You go first, entering all the words you can ";
   cout << "find that are formed by tracing adjoining ";
   cout << "letters. Two letters adjoin if they are next ";
   cout << "to each other horizontally, vertically, or ";
   cout << "diagonally. A letter can only be used once ";
   cout << "in each word. Words must be at least four ";
   cout << "letters long and can be counted only once. ";
   cout << "You score points based on word length: a ";
   cout << "4-letter word is worth 1 point, 5-letters ";
   cout << "earn 2 points, and so on. After your puny ";
   cout << "brain is exhausted, I, the supercomputer, ";
   cout << "will find all the remaining words and double ";
   cout << "or triple your paltry score." << endl << endl;
}

void setupBoard(Grid<char> & gameBoard) {
	string boardSizeString = getLine("Do you want to play the 4x4 version or the 5x5 version (4/5)? ");
	
	int boardSize = atoi(boardSizeString.c_str());
	drawBoard(boardSize, boardSize);
	gameBoard.resize(boardSize, boardSize);

	cout << endl;
	
	string manualSetup= getLine("Do you want to enter you own values (y/n)? ");
	if (manualSetup == "y") {
		setupBoardManually(gameBoard);
	}
	else {
		setupBoardRandomly(gameBoard);
	}

	cout << endl;
}

void setupBoardManually(Grid<char> & gameBoard) {
	int numRows = gameBoard.numRows();
	string boardConfig = getLine("Enter the letters you want on the board: ");
	boardConfig = toUpperCase(boardConfig);
	displayAndSetCubes(gameBoard, boardConfig);
	
}

void displayAndSetCubes(Grid<char> & gameBoard, string boardConfig) {
	int numRows = gameBoard.numRows();

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numRows; j++) {
			char ch = boardConfig[i * numRows + j];
				gameBoard[i][j] = ch;
				labelCube(i, j, ch);
		}
	}
}

void setupBoardRandomly(Grid<char> & gameBoard) {
	int numRows = gameBoard.numRows();
	Vector<string> cubes;

	if (numRows == 4) {
		for (int i = 0; i < 16; i++) {
			cubes.add(STANDARD_CUBES[i]);
		}
	}
	else if (numRows == 5) {
		for (int i = 0; i < 25; i++) {
			cubes.add(BIG_BOGGLE_CUBES[i]);
		}
	}

	randomizeCubes(cubes);

	string boardConfig = "";

	for (int i = 0; i < cubes.size(); i++) {
		boardConfig += cubes[i].at(randomInteger(0, cubes[i].length() - 1));
	}

	displayAndSetCubes(gameBoard, boardConfig);
}

void randomizeCubes(Vector<string> & cubes) {
	for (int i = 0; i < cubes.size(); i++) {
		string tmp = cubes[i];
		cubes[i] = cubes[randomInteger(0, cubes.size() - 1)];
		cubes[randomInteger(0, cubes.size() - 1)] = tmp;
	}
}

void playerTurn(Grid<char> & gameBoard, Lexicon & lex) {
	Player player = HUMAN;
	Lexicon usedWords;
	while (true) {
		string word = getLine("Enter a word (blank to finish): ");
		word = toUpperCase(word);
		clearBoardOfHighlights(gameBoard);
		if (word == "") break;
		else if (word.length() < 4) cout << "Word needs to be at least four characters long." << endl;
		else if (!isWord(word, lex)) cout << "Not a valid word." << endl;
		else if (usedWords.contains(word)) cout << "You already entered this word." << endl;
		else if (!onBoard(gameBoard, word)) cout << "Not on board" << endl;
		else {
			recordWordForPlayer(word, player);
		}
		
		usedWords.add(word);
	}
}

bool isWord(string word, Lexicon & lex) {
	if (lex.contains(word)) return true;
	else return false;
}

bool onBoard(Grid<char> & gameBoard, string word) {
	Grid<bool> visited(gameBoard.numCols(), gameBoard.numCols());
	foreach(bool bl in visited) {
		bl = false;
	}
	for (int i = 0; i < gameBoard.numCols(); i++) {
		for (int j = 0; j < gameBoard.numCols(); j++) {
			char currLetter = toupper(gameBoard[i][j]);
			string emptyString = ""; 
			string currentWord = emptyString + currLetter;
			if (wordHere(gameBoard, visited, word, currentWord, i, j, 0)) 
				return true;
		}
	}
	return false;
}


bool wordHere(Grid<char> & gameBoard, Grid<bool> & visited, string word, string curr, int x, int y, int count) {
	if (word == curr) {
		highlightCube(x, y, true);
		return true;
	}
	if (count >= word.length() || word[count] != gameBoard[x][y]) {
		visited[x][y] = false;
		return false;
	}
	visited[x][y] = true;
	//left
	if (gameBoard.inBounds(x, y-1) && visited[x][y-1] == false) { 
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x][y-1], x, y-1, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}
	
	//bottom-left
	if (gameBoard.inBounds(x+1, y-1) && visited[x+1][y-1] == false) { 
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x+1][y-1], x+1, y-1, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}
	
	//bottom
	if (gameBoard.inBounds(x+1, y) && visited[x+1][y] == false) { 
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x+1][y], x+1, y, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}

	//bottom-right
	if (gameBoard.inBounds(x+1, y+1 ) && visited[x+1][y+1] == false) {
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x+1][y+1], x+1, y+1, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}
	
	//right
	if (gameBoard.inBounds(x, y+1) && visited[x][y+1] == false) {
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x][y+1], x, y+1, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}
	
	//top-right
	if (gameBoard.inBounds(x-1, y+1) && visited[x-1][y+1] == false) { 
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x-1][y+1], x-1, y+1, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}
	
	//top
	if (gameBoard.inBounds(x-1, y) && visited[x-1][y] == false) { 
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x-1][y], x-1, y, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}
	
	//top-left
	if (gameBoard.inBounds(x-1, y-1) && visited[x-1][y-1] == false) {
		if (wordHere(gameBoard, visited, word, curr + gameBoard[x-1][y-1], x-1, y-1, count + 1)) {
			highlightCube(x, y, true);
			visited[x][y] = false;
			return true;
		}
	}

	visited[x][y] = false;
	return false;
}

void clearBoardOfHighlights(Grid<char> & gameBoard) {
	int size = gameBoard.numCols();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			highlightCube(i,j, false);
		}
	}
}



void computerTurn(Grid<char> & gameBoard, Lexicon & lex) {
	int size = gameBoard.numCols();
	Lexicon usedWords;
	Grid<bool> visited(size, size);
	foreach(bool bl in visited) {
		bl = false;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			displayWordsStartingHere(gameBoard, visited, lex, usedWords, "", i, j);
		}
	}
}

void displayWordsStartingHere(Grid<char> & gameBoard, Grid<bool> & visited, Lexicon & lex, Lexicon & usedWords, string current, int x, int y) {
	if (gameBoard.inBounds(x, y) && visited[x][y] == false) {
		char currentLetter = gameBoard[x][y];
		current = current + currentLetter;
		
		if (!lex.containsPrefix(current)) {
			visited[x][y] = false;
			return;
		}
		if (lex.contains(current) && current.length() > 3 && !usedWords.contains(current)) {
			usedWords.add(current);
			Player player = COMPUTER;
			recordWordForPlayer(current, player);
		}

		visited[x][y] = true;

		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x + 1, y - 1);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x + 1, y);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x + 1, y + 1);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x - 1, y - 1);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x - 1, y);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x - 1, y + 1);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x, y + 1);
		displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x, y - 1);

		/*for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 && j != 0) {
					displayWordsStartingHere(gameBoard, visited, lex, usedWords, current, x + i, y + j);
				}
			}
		}*/
	
		visited[x][y] = false;

	 }
}
