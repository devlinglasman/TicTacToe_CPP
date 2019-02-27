#pragma once

#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "Board.hpp"
#include "Mode.hpp"
#include "Mark.hpp"

using namespace std;

static const string newline = "\n";
static const string XString = "X";
static const string OString = "O";
static const string welcomeMessage = "Hi! Welcome to Tic Tac Toe";
static const string askForModeMessage = "Please enter one of the following numbers to pick the game mode:"
+ newline + "1 - human vs human" + newline + "2 - human vs computer" + newline +
"3 - computer vs human" + newline + "4 - computer vs computer";
static const string askForTileMessage = "Please pick a tile";
static const string displayMoveMessage = "Here's the move: ";
static const string winnerMessage = " is the winner!";
static const string drawMessage = "It was a draw...";
static const string invalidInputMessage = "That input was not valid...";

namespace training {
	class UI {
	public:
		explicit UI(istream & = cin, ostream & = cout, int = 0);

		int getValidMove(const Board & m_Board);

		void welcome();

		void displayMove(const Board & m_Board);

		void announceWinner(Mark m_Mark);

		void announceDraw();

		void announceInvalidInput();

		int getValidMode();

	private:
		istream & m_Input;
		ostream &m_Output;
		int m_delayTime;
		string getInput();

		bool isInputValid(string input, const Board &m_Board);

		string getMarkAsString(Mark m_Mark, int number);

		string getOccupiedMarkAsString(Mark m_Mark);

		string getTileInput(const Board & m_Board);

		string getModeInput();

		void askForTile(const Board & m_Board);

		bool isModeValid(string input);

		string outputBoard(const Board & m_Board);

		void clearScreen();
	};
}