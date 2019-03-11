#pragma once

#include <array>
#include <vector>
#include "SudokuBoard.h"
#include "SudokuSolver.h"

int main();
std::vector<std::string> FileRead(std::string file_name);
void FileWrite(std::string file_name);
std::string GetBoardAsString(SudokuBoard board)