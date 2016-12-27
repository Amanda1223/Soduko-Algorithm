#include <iostream>


using namespace std;
#include "Sudoku.h"

void solveOne();
void solveTwo();
void solveThree();

int main()
{
	solveOne();
	solveTwo();
	solveThree();
	
	return 0;
}


//#################  TESTING CODE  ####################
void solveOne() {
	Sudoku sudocode("easypuzzle1.txt");
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.bruteForce();

	system("pause");
}

void solveTwo() {
	Sudoku sudocode("easypuzzle2.txt");
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.bruteForce();

	system("pause");
}

void solveThree() {
	Sudoku sudocode("easypuzzle3.txt");
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.bruteForce();

	system("pause");
}