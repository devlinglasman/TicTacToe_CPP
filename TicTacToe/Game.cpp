#include "Game.hpp"

using namespace std;

namespace training {
	Game::Game(Player &playerOne, Player &playerTwo, UI &ui, int m_Dimension)
		: m_PlayerOne(playerOne),
		m_PlayerTwo(playerTwo),
		ui(ui),
		m_Board(Board(m_Dimension)) {}

	void Game::play() {
		Player &activePlayer = m_PlayerOne;
		ui.welcome();
		playAllTurns(activePlayer);
	}

	bool Game::isGameOver() const {
		return m_Board.isGameOver();
	}

	void Game::playAllTurns(Player &activePlayer) {
		playTurn(activePlayer);
		if (isGameOver()) {
			announceResult(activePlayer);
		}
		else {
			Player &nextPlayer = alternate(activePlayer);
			playAllTurns(nextPlayer);
		}
	}

	void Game::playTurn(Player &activePlayer) {
		int move = activePlayer.getMove(m_Board);
		m_Board.setMark(move, activePlayer.getMark());
		ui.displayMove(m_Board);
	}

	Player &Game::alternate(Player &activePlayer) {
		return (&activePlayer == &m_PlayerOne) ? m_PlayerTwo : m_PlayerOne;
	}

	void Game::announceResult(Player &activePlayer) {
		(m_Board.isWin()) ? ui.announceWinner(activePlayer.getMark()) : ui.announceDraw();
	}
}