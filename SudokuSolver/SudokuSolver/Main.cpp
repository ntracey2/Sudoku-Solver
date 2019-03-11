#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include "FileIO.h"

#include <array>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

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

int main() {
	std::string input;
	std::cout << "Enter the file to read from" << std::endl;

	std::cin >> input;
	std::vector<std::string> puzzles = FileRead(input);
	
	std::cout << "Enter the file to write to or enter \"print\" to print to screen" << std::endl;
	input.clear();
	std::cin >> input;

	std::vector<std::string> solved_puzzles;
	for (std::string p : puzzles) {
		SudokuBoard b(p);
		
		std::string solution = GetBoardAsString(GetSolvedBoard(b));
		solved_puzzles.push_back(solution);
	}
	if (input == "print") {
		for (std::string s : solved_puzzles) {
			std::cout << SudokuBoard(s) << "_____________________" << std::endl;
		}
	} else {
		FileWrite(input, solved_puzzles);
	}
	return 0;
}



