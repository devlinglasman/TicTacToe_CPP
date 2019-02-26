#include "pch.h"
#include "Board.hpp"

Board::Board(const int m_Dimension) : m_Dimension(m_Dimension) {
	int size = m_Dimension * m_Dimension;
	m_Marks.assign(static_cast<unsigned long>(size), _);
}

bool Board::isGameOver() const {
	return isDraw();
}

bool Board::isDraw() const {
	for (auto m_Mark : m_Marks) {
		if (m_Mark == _)
			return false;
	}
	return true;
}