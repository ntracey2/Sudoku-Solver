#include <array>
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