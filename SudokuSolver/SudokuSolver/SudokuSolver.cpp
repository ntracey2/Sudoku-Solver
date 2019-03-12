// SudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SudokuSolver.h"
#include "SudokuBoard.h"
#include <iostream>
#include <array>

SudokuBoard GetSolvedBoard(SudokuBoard board) {
	std::array<std::array<char, kBoardSize>, kBoardSize> board_array = board.get_board_array();
	SolveBoard(board_array);
	SudokuBoard n(board_array);
	return n;
}

bool SolveBoard(std::array<std::array<char, kBoardSize>, kBoardSize> & board) {
	if (GetEmptyPoint(board)[0] == 0) {
		return true;
	}
	int x = GetEmptyPoint(board)[1];
	int y = GetEmptyPoint(board)[2];
	std::string chars = "123456789";
	for (int i = 0; i < chars.length(); i++) {
		if (CanPlaceDigit(board, chars.at(i), x, y)) {
			board[y][x] = chars.at(i);
			if (SolveBoard(board)) {
				return true;
			} else {
				board[y][x] = '_';
			}
		}
	}
	return false;
}

std::array<int, 3> GetEmptyPoint(std::array<std::array<char, kBoardSize>, kBoardSize> board) {
	std::array<int, 3> point;
	point[0] = 0; //specify point not found
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == '_') {
				point[0] = 1; //point found
				point[1] = j;
				point[2] = i;
				return point;
				//std::cout << i << j;
			}
		}
	}
	return point;
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

std::string GetBoardAsString(SudokuBoard board) {
	std::string board_string;
	std::array<std::array<char, 9>, 9> board_array = board.get_board_array();
	for (int i = 0; i < board_array.size(); i++) {
		for (int j = 0; j < board_array[0].size(); j++) {
			board_string.push_back(board_array[i][j]);
		}
	}
	return board_string;
}