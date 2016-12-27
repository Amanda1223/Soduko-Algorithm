#pragma once

#include <iostream>

#define ROW_COUNT 9
#define COLUMN_COUNT 9

#define INNER_ROW_COUNT 3
#define INNER_COL_COUNT 3
#define OUTER_ROW_COUNT 3
#define OUTER_COL_COUNT 3

using namespace std;

class BruteForce {
public:
	BruteForce(int[9][9]);
	bool solve();
	void printBoard();
	
private:
	// Member Variables.
	int board[ROW_COUNT][COLUMN_COUNT];
	int boxSetBoard[OUTER_ROW_COUNT][OUTER_COL_COUNT][INNER_ROW_COUNT][INNER_COL_COUNT];
	int original[ROW_COUNT][COLUMN_COUNT];

	// Utility Functions.
	void set(int a_row, int a_col, int a_value);
	void unset(int a_row, int a_col);
	void next(int &x, int &y);
	void previous(int &x, int &y);
	bool isValid(int a_row, int a_col, int a_value);
	bool recursive(int a_row, int a_col);
};