#include "Player.hpp"

namespace training {
	Player::Player(const Mark m_Mark)
		: m_Mark(m_Mark) {}

	Mark Player::getMark() const {
		return m_Mark;
	}
}