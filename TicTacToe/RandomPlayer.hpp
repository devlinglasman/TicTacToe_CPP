#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace training {
	class RandomPlayer : public Player {
	public:
		explicit RandomPlayer(Mark m_Mark);

		int getMove(const Board & m_Board) override;

	private:
		int generateRandInRange();
	};
}