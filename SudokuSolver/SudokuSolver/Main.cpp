#include <array>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

#include "main.h"
#include "SudokuBoard.h"
#include "SudokuSolver.h"

int main() {
	std::string input;
	std::cout << "Enter the file to read from" << std::endl;

	std::cin >> input;
	std::vector<std::string> puzzles = FileRead(input);
	
	std::cout << "Enter the file to write to" << std::endl;
	input.clear();
	std::cin >> input;

	std::vector<std::string> solved_puzzles;
	for (std::string p : puzzles) {
		SudokuBoard b(p);
		
		std::string solution = GetBoardAsString(GetSolvedBoard(b));
		solved_puzzles.push_back(solution);
	}

	FileWrite(input);
}

std::vector<std::string> FileRead(std::string file_name) {
	std::ifstream file(file_name);

	std::string line;
	std::vector<std::string> puzzles;

	if (!file) {
		std::cout << "Invalid file" << std::endl;
	} else {
		while (std::getline(file, line)) {
			puzzles.push_back(line);
		}
	}
	file.close();
	if (puzzles.at(0) != "#spf1.0") {
		std::cout << "Invalid file spec" << std::endl;
	}
	puzzles.erase(puzzles.begin());
	return puzzles;
}

void FileWrite(std::string file_name, std::vector<std::string> solutions) {
	std::ofstream file;
	file.open(file_name);
	for (std::string s : solutions) {
		file << s;
	}
	file.close();
}

std::string GetBoardAsString(SudokuBoard board)
{
	std::string board_string;
	std::array<std::array<char, 9>, 9> board_array = board.get_board_array();
	for (int i = 0; i < board_array.size(); i++) {
		for (int j = 0; j < board_array[0].size(); j++) {
			board_string.push_back(board_array[i][j]);
		}
	}
	return board_string;
}