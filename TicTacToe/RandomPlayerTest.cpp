#include <gtest/gtest.h>
#include "RandomPlayer.hpp"
#include "Board.hpp"
#include "Mark.hpp"

namespace training {
	TEST(RandomPlayer, withinRange) {
		RandomPlayer comp(X);
		Board board(3);
		int move = comp.getMove(board);

		EXPECT_TRUE(move <= 9);
		EXPECT_TRUE(move >= 1);
	}
}