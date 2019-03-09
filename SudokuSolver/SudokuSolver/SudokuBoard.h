#pragma once
#include <string>
#include <array>
const int kBoardSize = 9;
class SudokuBoard {
	private:
		std::array<std::array<char, kBoardSize>, kBoardSize> board_array;
		std::array<std::array<char, kBoardSize>, kBoardSize> GetMatrix(std::string board);
	public:
		SudokuBoard(std::string board);
		std::array<std::array<char, kBoardSize>, kBoardSize> get_board_array();
};
