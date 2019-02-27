#include "UI.hpp"

using namespace std;

namespace training {
	UI::UI(istream &input, ostream &output, int delayTime)
		: m_Input(input), m_Output(output), m_delayTime(delayTime) {}

	int UI::getValidMove(const Board &board) {
		string input = getTileInput(board);
		while (!isInputValid(input, board)) {
			announceInvalidInput();
			input = getTileInput(board);
		}
		return stoi(input);
	}

	void UI::welcome() {
		clearScreen();
		m_Output << welcomeMessage + newline + newline;
	}

	void UI::displayMove(const Board &board) {
		clearScreen();
		m_Output << displayMoveMessage + newline + newline + outputBoard(board) + newline;
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delayTime));
		clearScreen();
	}

	void UI::announceWinner(const Mark mark) {
		m_Output << getOccupiedMarkAsString(mark) + winnerMessage + newline + newline;
	}

	void UI::announceDraw() {
		m_Output << drawMessage + newline + newline;
	}

	void UI::announceInvalidInput() {
		clearScreen();
		m_Output << invalidInputMessage + newline + newline;
	}

	int UI::getValidMode() {
		string input = getModeInput();
		while (!isModeValid(input)) {
			announceInvalidInput();
			input = getModeInput();
		}
		return stoi(input);
	}

	bool UI::isModeValid(const string input) {
		for (auto mode : allModes) {
			if (input == to_string(mode + 1)) {
				return true;
			}
		}
		return false;
	}

	string UI::getModeInput() {
		m_Output << askForModeMessage + newline + newline;
		return getInput();
	}

	string UI::getTileInput(const Board &board) {
		askForTile(board);
		return getInput();
	}

	string UI::getInput() {
		string input;
		m_Input >> input;
		return input;
	}

	bool UI::isInputValid(const string input, const Board &board) {
		int dimension = board.getM_Dimension();
		int size = dimension * dimension;
		for (int i = 1; i < size + 1; ++i) {
			if (input == to_string(i)) {
				return true;
			}
		}
		return false;
	}

	string UI::outputBoard(const Board &board) {
		int dimension = board.getM_Dimension();
		int size = dimension * dimension;
		string boardRepresentation;
		for (int i = 1; i < size + 1; ++i) {
			boardRepresentation.append("[" + getMarkAsString(board.getMark(i), i) + "] ");
			if (i % dimension == 0) {
				boardRepresentation.append(newline);
			}
		}
		return boardRepresentation;
	}

	string UI::getMarkAsString(const Mark mark, const int number) {
		return (mark == _) ? to_string(number) : getOccupiedMarkAsString(mark);
	}

	string UI::getOccupiedMarkAsString(const Mark mark) {
		return (mark == X) ? XString : OString;
	}

	void UI::askForTile(const Board &board) {
		m_Output << outputBoard(board) + newline + askForTileMessage + newline;
	}

	void UI::clearScreen() {
		m_Output << string(1000, '\n');
	}
}