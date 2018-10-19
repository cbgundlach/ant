/*********************************************************************
** Program name: AntBoard.hpp
** Author: Christopher Gundlach
** Date: 10/07/18
** Description: This is the header file for the AntBoard class in AntBoard.cpp. It sets the private variables
				for the class, which includes both dynamic bards used for keeping track of the ant's postion
				as well as integers to remember the max size of the board. It also has the public methods to
				create the boards and make a move, as well as a destructor for the class.
*********************************************************************/

#ifndef ANTBOARD_HPP
#define ANTBOARD_HPP
#include "Ant.hpp"

class AntBoard
{
private:
	char **charBoard;
	bool **boolBoard;
	int maxRow;
	int maxColumn;
public:
	AntBoard();
	void createBoard(int, int);
	void makeMove(Ant *, int);
	void printBoard();
	~AntBoard();
};



#endif // !ANTBOARD_HPP

