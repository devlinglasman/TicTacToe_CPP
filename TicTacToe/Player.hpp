#pragma once

#include "Mark.hpp"

namespace training {
	class Board;

	struct Player {
		explicit Player(Mark m_Mark);

		virtual int getMove(const Board &m_Board) = 0;

		Mark getMark() const;

		virtual ~Player() = default;

	private:
		Mark m_Mark;
	};
}