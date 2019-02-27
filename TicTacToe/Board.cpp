#include "Board.hpp"
#include <cmath>
#include <iostream>

using namespace std;

namespace training {
	Board::Board(const int m_Dimension) : m_Dimension(m_Dimension) {
		int size = m_Dimension * m_Dimension;
		m_Marks.assign(static_cast<unsigned long>(size), _);
	}

	void Board::setMark(int position, Mark mark) {
		m_Marks[position - 1] = mark;
	}

	bool Board::isGameOver() const {
		return isWin() || isDraw();
	}

	Board Board::withMarks(const std::vector<Mark> &marks) {
		int thisDimension = static_cast<int>(sqrt(marks.size()));
		Board board(thisDimension);
		for (unsigned int i = 0; i < marks.size(); i++) {
			board.setMark(i + 1, marks[i]);
		}
		return board;
	}

	bool Board::isDraw() const {
		for (auto m_Mark : m_Marks) {
			if (m_Mark == _)
				return false;
		}
		return true;
	}

	Mark Board::getMark(int position) const {
		return m_Marks[position - 1];
	}

	bool Board::isWin() const {
		return anyLineWin(getColumnIndices()) ||
			anyLineWin(getRowIndices()) ||
			anyLineWin(getDiagIndices());
	}

	bool Board::anyLineWin(std::vector<std::vector<int>> lines) const {
		for (const auto &line : lines) {
			if (isLineWin(line)) {
				return true;
			}
		}
		return false;
	}

	bool Board::isLineWin(std::vector<int> positions) const {
		return m_Marks[positions[0]] != _ && allMarksIdentical(positions);
	}

	bool Board::allMarksIdentical(std::vector<int> positions) const {
		int firstMark = m_Marks[positions[0]];
		for (auto position : positions) {
			if (m_Marks[position] != firstMark)
				return false;
		}
		return true;
	}

	vector<vector<int>> Board::getColumnIndices() const {
		std::vector<int> colStartingValues = getColStartingValues();
		std::vector<std::vector<int>> allCols;
		allCols.reserve((unsigned long)m_Dimension);
		for (auto startingValue : colStartingValues) {
			allCols.push_back(makeCol(startingValue));
		}
		return allCols;
	}

	vector<int> Board::getColStartingValues() const {
		std::vector<int> colStartingValues;
		colStartingValues.reserve((unsigned long)m_Dimension);
		for (int i = 0; i < m_Dimension; ++i) {
			colStartingValues.push_back(i);
		}
		return colStartingValues;
	}

	std::vector<int> Board::makeCol(int startingValue) const {
		std::vector<int> line;
		line.reserve((unsigned long)m_Dimension);
		for (int i = 0; i < m_Dimension; ++i) {
			int incrementor = startingValue + i * m_Dimension;
			line.push_back(incrementor);
		}
		return line;
	}

	vector<vector<int>> Board::getRowIndices() const {
		std::vector<int> rowStartingValues = getRowStartingValues();
		std::vector<std::vector<int>> allRows;
		allRows.reserve((unsigned long)m_Dimension);
		for (auto startingValue : rowStartingValues) {
			allRows.push_back(makeRow(startingValue));
		}
		return allRows;
	}

	vector<int> Board::getRowStartingValues() const {
		std::vector<int> rowStartingValues;
		rowStartingValues.reserve((unsigned long)m_Dimension);
		for (int i = 0; i < m_Dimension; ++i) {
			rowStartingValues.push_back(i * m_Dimension);
		}
		return rowStartingValues;
	}

	std::vector<int> Board::makeRow(int startingValue) const {
		std::vector<int> line;
		line.reserve((unsigned long)m_Dimension);
		for (int i = 0; i < m_Dimension; ++i) {
			line.push_back(startingValue);
			startingValue++;
		}
		return line;
	}



	vector<vector<int>> Board::getDiagIndices() const {
		std::vector<std::vector<int>> allDiags;
		allDiags.push_back(makeLeftDiag());
		allDiags.push_back(makeRightDiag());
		return allDiags;
	}

	std::vector<int> Board::makeLeftDiag() const {
		std::vector<int> line;
		line.reserve((unsigned long)m_Dimension);
		for (int j = 0; j < m_Dimension; ++j) {
			int incrementor = j * m_Dimension + j;
			line.push_back(incrementor);
		}
		return line;
	}

	std::vector<int> Board::makeRightDiag() const {
		std::vector<int> line;
		line.reserve((unsigned long)m_Dimension);
		for (int j = 1; j < m_Dimension + 1; ++j) {
			int incrementor = j * m_Dimension - j;
			line.push_back(incrementor);
		}
		return line;
	}


	bool Board::tileOccupied(int position) const {
		return !(m_Marks[position - 1] == _);
	}

	const int Board::getM_Dimension() const {
		return m_Dimension;
	}
}