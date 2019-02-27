#include "HumanPlayer.hpp"

namespace training {
	HumanPlayer::HumanPlayer(const Mark m_Mark, UI &ui)
		: Player(m_Mark), ui(ui) {
	}

	int HumanPlayer::getMove(const Board &m_Board) {
		int tileChoice = ui.getValidMove(m_Board);
		while (m_Board.tileOccupied(tileChoice)) {
			ui.announceInvalidInput();
			tileChoice = ui.getValidMove(m_Board);
		}
		return tileChoice;
	}
}