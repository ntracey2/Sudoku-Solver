#pragma once
#include <array>

const int kBoardSize = 9;

bool SolveBoard(std::array<std::array<char, kBoardSize>, kBoardSize> board);
bool CanPlaceDigit(std::array<std::array<char, kBoardSize>, kBoardSize> board, char digit, int x, int y);
