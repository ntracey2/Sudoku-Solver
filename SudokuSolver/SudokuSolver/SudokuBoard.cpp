#include <array>
#include <iostream>
#include "SudokuBoard.h"

SudokuBoard::SudokuBoard(std::string board) {
	board_array = GetMatrix(board);
}

std::array<std::array<char, kBoardSize>, kBoardSize> SudokuBoard::GetMatrix(std::string board) {
	std::array<std::array<char, 9>, 9> sudoku;
	int j = 0;
	for (int i = 0; i < board.length(); i++) {
		if (i != 0 && i % 9 == 0) {
			j++;
		}
		sudoku[j][i % 9] = board.at(i);
		if (j == 9) {
			break;
		}
	}
	return sudoku;
}

std::array<std::array<char, kBoardSize>, kBoardSize> SudokuBoard::get_board_array() {
	return board_array;
}

std::ostream & operator<<(std::ostream & os, const SudokuBoard & board)
{
	for (int i = 0; i < kBoardSize; i++) {
		for (int j = 0; j < kBoardSize; j++) {
			os << board.board_array[i][j] << " ";
			if (j != 0 && j != 8 && (j + 1) % 3 == 0) {
				os << "| ";
			}
		}
		if (i != 0 && (i + 1) % 3 == 0) {
			//os << std::endl << "_ _ _  _ _ _  _ _ _";
			os << std::endl;
		}
		os << std::endl;
	}
	return os;
}
