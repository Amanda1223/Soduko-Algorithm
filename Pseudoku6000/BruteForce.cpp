#include "BruteForce.h"

BruteForce::BruteForce(int a_original[9][9])
{
	for (int row = 0; row < ROW_COUNT; row++)
		for (int col = 0; col < COLUMN_COUNT; col++)
		{
			original[row][col] = a_original[row][col];
			board[row][col] = original[row][col];
			boxSetBoard[row / 3][col / 3][row % 3][col % 3] = original[row][col];
		}
}

bool BruteForce::solve()
{
	if (true == recursive(0, 0))
	{
		cout << "Solution:\n";
		printBoard();
		return true;
	}
	else
	{
		cout << "No solution found.\n";
		return false;
	}

}

void BruteForce::set(int a_row, int a_col, int a_value)
{// Set value a_value at row a_row and column a_col.
	board[a_row][a_col] = a_value;
	boxSetBoard[a_row / 3][a_col / 3][a_row % 3][a_col % 3] = a_value;
}

void BruteForce::unset(int a_row, int a_col)
{// Unset whatever value was at row a_row and column a_col.
	board[a_row][a_col] = original[a_row][a_col];
	boxSetBoard[a_row / 3][a_col / 3][a_row % 3][a_col % 3] = original[a_row][a_col];
}

void BruteForce::next(int &x, int &y)
{// Move to the next position on the board.
	y++;
	if (y == 9)
	{
		y = 0;
		x++;
	}
}

void BruteForce::previous(int &x, int &y)
{// Move to the previous position on the board.
	y--;
	if (y < 0)
	{
		y = 8;
		x--;
	}
}

bool BruteForce::isValid(int a_row, int a_col, int a_value)
{
	// (1) Not already in that row.
	for (int y = 0; y < 9; y++)
	{
		if (a_value == board[a_row][y])
			return false;
	}
	// (2) Not already in that column.
	for (int x = 0; x < 9; x++)
	{
		if (a_value == board[x][a_col])
			return false;
	}
	// (3) Not already in that boxSet.
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (a_value == boxSetBoard[a_row / 3][a_col / 3][x][y])
				return false;
		}
	}
	// No conflicts, indicate that the move is valid.
	return true;
}

bool BruteForce::recursive(int a_row, int a_col)
{
	if (0 != original[a_row][a_col])
	{// Set as original value.
		set(a_row, a_col, original[a_row][a_col]);
		int tRow = a_row,
			tCol = a_col;
		next(tRow, tCol);

		if (false == recursive(tRow, tCol))
		{// Next box said value was bad, undo. Pass it on.
			unset(a_row, a_col);
			return false;
		}
		else
		{// Next box said value was good, solved. Pass it on.
			return true;
		}
	}
	else
	{// Find a valid value.
		for (int i = 1; i <= 9; i++)
		{
			if (true == isValid(a_row, a_col, i))
			{
				set(a_row, a_col, i);
				int tRow = a_row,
					tCol = a_col;
				next(tRow, tCol);
				if (!(tRow < 9))
				{// Solved! Pass it on.
					return true;
				}
				if (false == recursive(tRow, tCol))
				{// Next box said value was bad, continue to the next value.
					unset(a_row, a_col);
					continue;
				}
				else
				{// Next box said value was good, solved. Pass it on.
					return true;
				}
			}
		}
		// Unable to find a valid value, tell previous box its value was bad.
		unset(a_row, a_col);
		return false;
	}
}

void BruteForce::printBoard()
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int col = 0; col < COLUMN_COUNT; col++)
			cout << board[row][col] << ' ';
		cout << endl;
	}
}