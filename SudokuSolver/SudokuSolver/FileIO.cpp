#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

std::vector<std::string> FileRead(std::string file_name) {
	std::ifstream file(file_name);

	std::string line;
	std::vector<std::string> puzzles;

	if (!file) {
		std::cout << "Invalid file" << std::endl;
	}
	else {
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
		file << s << std::endl;
	}
	file.close();
}