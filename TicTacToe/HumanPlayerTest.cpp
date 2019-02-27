#include <gtest/gtest.h>
#include "HumanPlayer.hpp"

using namespace std;

namespace training {
	TEST(HumanPlayer, inputTileOccupiedValidation) {
		istringstream input("1" + newline + "2" + newline);
		ostringstream output;
		UI ui(input, output);
		HumanPlayer player = HumanPlayer(X, ui);
		Board board(3);
		board.setMark(1, X);

		EXPECT_TRUE(player.getMove(board) == 2);
	}
}