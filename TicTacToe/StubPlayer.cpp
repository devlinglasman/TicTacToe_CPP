#include "StubPlayer.hpp"

namespace training {
	StubPlayer::StubPlayer(const Mark m_Mark)
		: Player(m_Mark), m_CurrentIndex(0) {}

	int StubPlayer::getMove(const Board & m_Board) {
		return m_SpacesToReturn[m_CurrentIndex++];
	}

	void StubPlayer::willSelectSpaces(const std::vector<int> m_Spaces) {
		m_SpacesToReturn = m_Spaces;
	}
}