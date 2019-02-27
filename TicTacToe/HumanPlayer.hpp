#pragma once

#include "Mark.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "UI.hpp"

namespace training {
	class HumanPlayer : public Player {
	public:
		explicit HumanPlayer(Mark m_Mark, UI &ui);

		int getMove(const Board & m_Board) override;

	private:
		UI & ui;
	};
}