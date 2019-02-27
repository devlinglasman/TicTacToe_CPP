#include "gtest/gtest.h"
#include "Board.hpp"
#include "Mark.hpp"


TEST(Board, EmptyBoardCreation) {
	Board board(3);
	EXPECT_FALSE(board.isGameOver());
}