// SudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SudokuSolver.h"
#include <iostream>
#include <array>

//const int kBoardSize = 9;

bool SolveBoard(std::array<std::array<char, kBoardSize>, kBoardSize> board)
{
	return false;
}

bool CanPlaceDigit(std::array<std::array<char, kBoardSize>, kBoardSize> board, char digit, int x, int y) {
	for (int i = 0; i < kBoardSize; i++) {
		if (i != x) {
			if (board[y][i] == digit) {
				return false;
			}
			if (board[i][x] == digit) {
				return false;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i + y - y % 3][j + x - x % 3] == digit) {
				return false;
			}
		}
	}
	return true;
}

