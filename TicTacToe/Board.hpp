#pragma once

#include "pch.h"
#include "Mark.hpp"
#include <vector>
#include <array>


class Board {

public:
	explicit Board(int m_Dimension);

	bool isGameOver() const;
	bool isDraw() const;

private:
	const int m_Dimension;
	std::vector<Mark> m_Marks;
};