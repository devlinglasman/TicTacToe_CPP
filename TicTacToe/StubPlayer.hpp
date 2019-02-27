#pragma once

#include "Player.hpp"
#include "Mark.hpp"
#include <vector>

namespace training {
	class StubPlayer : public Player {
	public:
		explicit StubPlayer(Mark m_Mark);

		int getMove(const Board & m_Board) override;

		void willSelectSpaces(std::vector<int> m_Spaces);

	private:
		std::vector<int> m_SpacesToReturn;
		int m_CurrentIndex;
	};
}