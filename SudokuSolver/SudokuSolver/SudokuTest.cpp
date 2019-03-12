#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include "FileIO.h"


std::string kExampleBoard = "___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___";
std::string ExampleBoard1 = "2__3_____8_4_62__3_138__2______2_39_5_7___621_32__6____2___914_6_125_8_9_____1__2";
std::string kSolvedExampleBoard1 = "276314958854962713913875264468127395597438621132596487325789146641253879789641532";
SudokuBoard testBoard(kExampleBoard);
SudokuBoard hardBoard(ExampleBoard1);

TEST_CASE("Test GetMatrix") {
	SECTION("Test1") {
		REQUIRE(testBoard.get_board_array()[0][0] == '_');
	}
	SECTION("Test2") {
		REQUIRE(testBoard.get_board_array()[8][5] == '6');
	}
}

TEST_CASE("Test printing") {
	std::cout << testBoard;
}

TEST_CASE("Test GetEmptyPoint") {
	REQUIRE(GetEmptyPoint(hardBoard.get_board_array())[1] == 1);
	REQUIRE(GetEmptyPoint(hardBoard.get_board_array())[2] == 0);
}

TEST_CASE("Test solution") {
	SudokuBoard solved(kSolvedExampleBoard1);
	REQUIRE(solved.get_board_array() == GetSolvedBoard(hardBoard).get_board_array());
}

TEST_CASE("Test CanPlaceDigit valid location") {
	REQUIRE(CanPlaceDigit(hardBoard.get_board_array(), '7', 1, 0) == 1);
}

TEST_CASE("Test CanPlaceDigit invalid location") {
	REQUIRE(CanPlaceDigit(hardBoard.get_board_array(), '2', 1, 0) == 0);
}

TEST_CASE("Test getting puzzles from file") {
	REQUIRE(FileRead("PuzzleInput.txt")[0] == "2__3_____8_4_62__3_138__2______2_39_5_7___621_32__6____2___914_6_125_8_9_____1__2");
	REQUIRE(FileRead("PuzzleInput.txt")[1] == "___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___");
}

TEST_CASE("Test writing solutions to file") {
	std::vector<std::string> puzzles = FileRead("TestInput.txt");
	std::vector<std::string> solved_puzzles;
	for (std::string p : puzzles) {
		SudokuBoard b(p);
		std::string solution = GetBoardAsString(GetSolvedBoard(b));
		solved_puzzles.push_back(solution);
	}
	FileWrite("TestOutput.txt", solved_puzzles);

	REQUIRE(FileRead("TestOutput.txt") == solved_puzzles);
}

TEST_CASE("Test get board as string") {
	REQUIRE(GetBoardAsString(hardBoard) == ExampleBoard1);
}