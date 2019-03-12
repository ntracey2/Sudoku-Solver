#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include "FileIO.h"

#include <array>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>



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



