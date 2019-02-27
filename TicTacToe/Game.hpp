#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "UI.hpp"

using namespace std;

namespace training {
	class Game {
	public:
		Game(Player &playerOne, Player &playerTwo, UI &ui, int m_Dimension);

		void play();

		bool isGameOver() const;

	private:
		Board m_Board;
		Player &m_PlayerOne;
		Player &m_PlayerTwo;
		UI &ui;

		void playAllTurns(Player &activePlayer);

		void playTurn(Player &activePlayer);

		void announceResult(Player &activePlayer);

		Player &alternate(Player &activePlayer);
	};
}