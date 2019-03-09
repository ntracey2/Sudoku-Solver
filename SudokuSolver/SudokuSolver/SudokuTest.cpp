#define CATCH_CONFIG_MAIN

#include "SudokuBoard.h"
#include "catch.h"

std::string kExampleBoard = "___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___";
SudokuBoard testBoard(kExampleBoard);

TEST_CASE("Test GetMatrix") {
	SECTION("Test1") {
		REQUIRE(testBoard.get_board_array()[0][0] == '_');
	}
	SECTION("Test2") {
		REQUIRE(testBoard.get_board_array()[8][5] == '6');
	}
}