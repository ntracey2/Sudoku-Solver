#pragma once

#include <array>
#include "Constants.h"
#include "SudokuBoard.h"

bool SolveBoard(std::array<std::array<char, kBoardSize>, kBoardSize> & board);
bool CanPlaceDigit(std::array<std::array<char, kBoardSize>, kBoardSize> board, char digit, int x, int y);
std::array<int, 3> GetEmptyPoint(std::array<std::array<char, kBoardSize>, kBoardSize> board);
SudokuBoard GetSolvedBoard(SudokuBoard board);
 