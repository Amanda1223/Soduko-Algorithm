#include <iostream>
#include "Sudoku.h"

using namespace std;

#define FILE_PATH "I:\\[Work]\\2016 Fall Semester\\Analysis of Algorithms\\SudokuBoard.txt"

int main()
{
	Sudoku sudocode(FILE_PATH);
	sudocode.DisplayBoard();

	sudocode.SolvePuzzle();
	//sudocode.bruteForce();

	system("pause");
	return 0;
}