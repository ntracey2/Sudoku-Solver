#pragma once

#include <string>
#include <iostream>
#include <array>
#include "Constants.h"

class SudokuBoard {
	private:
		std::array<std::array<char, kBoardSize>, kBoardSize> board_array;
		std::array<std::array<char, kBoardSize>, kBoardSize> GetMatrix(std::string board);
		std::string board_string;
	public:
		SudokuBoard(std::string board);
		SudokuBoard(std::array<std::array<char, kBoardSize>, kBoardSize> board);
		std::array<std::array<char, kBoardSize>, kBoardSize> get_board_array();
		void set_board_array(std::array<std::array<char, kBoardSize>, kBoardSize> board);
		friend std::ostream& operator<<(std::ostream& os, const SudokuBoard& board);
		friend std::istream& operator>>(std::istream &in, const SudokuBoard &c);
};
