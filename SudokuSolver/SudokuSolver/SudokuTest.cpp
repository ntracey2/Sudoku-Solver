//#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "SudokuBoard.h"
#include "SudokuSolver.h"


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

TEST_CASE("Test solution") {
	SudokuBoard solved(kSolvedExampleBoard1);
	//std::cout << solved << std::endl;
	REQUIRE(solved.get_board_array() == GetSolvedBoard(hardBoard).get_board_array());
}