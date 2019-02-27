#include "gtest/gtest.h"
#include "Board.hpp"
#include "Mark.hpp"

namespace training {
	TEST(Board, EmptyBoardCreation) {
		Board board(3);
		EXPECT_FALSE(board.isGameOver());
	}

	TEST(Board, EmptyBoardCreation4x4) {
		Board board(4);
		EXPECT_FALSE(board.isGameOver());
	}

	TEST(Board, WithWinningColumn) {
		Board board = Board::withMarks({ O, X, X,
			O, O, X,
			_, _, X });
		EXPECT_TRUE(board.isWin());
	}

	TEST(Board, WithWinningRow) {
		Board board = Board::withMarks({ X, O, O,
			O, _, _,
			X, X, X });
		EXPECT_TRUE(board.isWin());
	}

	TEST(Board, WithWinningDiagonal) {
		Board board = Board::withMarks({ O, X, X,
			_, X, O,
			X, _, O
			});
		EXPECT_TRUE(board.isWin());
	}

	TEST(Board, EndingInDraw) {
		Board board = Board::withMarks({ X, X, O,
			O, O, X,
			X, O, X });
		EXPECT_TRUE(board.isDraw());
	}

	TEST(Board, WithWin4x4) {
		Board board = Board::withMarks({ X, X, X, X,
			O, O, X, _,
			O, O, X, O,
			O, X, _, _ });
		EXPECT_TRUE(board.isWin());
	}

	TEST(Board, WithDraw4x4) {
		Board board = Board::withMarks({ X, X, X, O,
			O, O, X, X,
			O, O, X, O,
			O, X, O, X });
		EXPECT_TRUE(board.isDraw());
	}
}