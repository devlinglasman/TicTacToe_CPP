#include <gtest/gtest.h>
#include "UI.hpp"

using namespace std;

namespace training {
	TEST(UI, InputIsNotNumberValidation) {
		istringstream input("asd" + newline + "1?" + newline + "" + newline + "1");
		ostringstream output;
		UI ui(input, output);
		Board board(3);

		EXPECT_TRUE(ui.getValidMove(board) == 1);
	}

	TEST(UI, InputIsNotInRangeValidation) {
		istringstream input("10" + newline + "0" + newline + "0.1" + newline + "1.0" + newline + "5");
		ostringstream output;
		UI ui(input, output);
		Board board(3);

		EXPECT_TRUE(ui.getValidMove(board) == 5);
	}

	TEST(UI, displayMove) {
		istringstream input("");
		ostringstream output;
		UI ui(input, output);
		Board board = Board::withMarks({ X, _, O,
			X, _, _,
			O, _, _ });
		ui.displayMove(board);

		EXPECT_TRUE(output.str().find(displayMoveMessage + newline + newline + "[X] [2] [O] " + newline
			+ "[X] [5] [6] " + newline + "[O] [8] [9] " + newline + newline));
	}

	TEST(UI, P1WinMessage) {
		istringstream input("");
		ostringstream output;
		UI ui(input, output);

		ui.announceWinner(X);

		EXPECT_TRUE(output.str() == "X is the winner!" + newline + newline);
	}

	TEST(UI, P2WinMessage) {
		istringstream input("");
		ostringstream output;
		UI ui(input, output);

		ui.announceWinner(O);

		EXPECT_TRUE(output.str() == "O is the winner!" + newline + newline);
	}

	TEST(UI, getModeWhenInitiallyOutOfRange) {
		istringstream input("0" + newline + "7" + newline + "1.1" + newline + "1");
		ostringstream output;
		UI ui(input, output);

		EXPECT_TRUE(ui.getValidMode() == 1);
	}

	TEST(UI, getModeWhenInitiallyNotNumber) {
		istringstream input("1a" + newline + "?3" + newline + "3");
		ostringstream output;
		UI ui(input, output);

		EXPECT_TRUE(ui.getValidMode() == 3);
	}
}