#pragma once

#include "Mark.hpp"
#include <vector>
#include <array>

namespace training {
	class Board {

	public:
		explicit Board(int m_Dimension);

		void setMark(int position, Mark mark);

		bool isGameOver() const;

		static Board withMarks(const std::vector<Mark> &marks);

		bool isWin() const;

		bool isDraw() const;

		bool tileOccupied(int position) const;

		Mark getMark(int position) const;

		const int getM_Dimension() const;

	private:
		const int m_Dimension;
		std::vector<Mark> m_Marks;

		bool anyLineWin(std::vector<std::vector<int>> lines) const;

		bool isLineWin(std::vector<int> positions) const;

		bool allMarksIdentical(std::vector<int> positions) const;

		std::vector<std::vector<int>> getColumnIndices() const;

		std::vector<int> getColStartingValues() const;

		std::vector<int> makeCol(int startingValue) const;

		std::vector<std::vector<int>> getRowIndices() const;

		std::vector<int> getRowStartingValues() const;

		std::vector<int> makeRow(int startingValue) const;

		std::vector<std::vector<int>> getDiagIndices() const;

		std::vector<int> makeLeftDiag() const;

		std::vector<int> makeRightDiag() const;
	};
}