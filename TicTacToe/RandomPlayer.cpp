#include <stdlib.h>
#include "RandomPlayer.hpp"

namespace training {
	RandomPlayer::RandomPlayer(const Mark m_Mark) : Player(m_Mark) {
	}

	int RandomPlayer::getMove(const Board &m_Board) {
		int tileChoice = generateRandInRange();
		while (m_Board.tileOccupied(tileChoice)) {
			tileChoice = generateRandInRange();
		}
		return tileChoice;
	}

	int RandomPlayer::generateRandInRange() {
		return rand() % 9 + 1;
	}
}