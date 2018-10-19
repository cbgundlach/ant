/*********************************************************************
** Program name: AntBoard.cpp
** Author: Christopher Gundlach
** Date: 10/07/18
** Description: This is the AntBoard class. It creates the two dynamic boards used in the program. The char board is for printing the board, and the bool
				board is for keeping track of the color of the board where the and is located. The makemove function uses switch statements to determine both how to 
				move the and and what color the board needs to be. the printBoard obviously prints the board to the screen, and the destructor deallocates 
				the memory of both arrays.
*********************************************************************/

#include "AntBoard.hpp"
#include "Ant.hpp"
#include<iostream>
#include<iomanip>

AntBoard::AntBoard() {}

void AntBoard::createBoard(int row, int column)
{
	//sets the max size for the columns and rows for later
	maxRow = row;
	maxColumn = column;

	//the char board is used for visually showing the position of the and and board colors
	charBoard = new char*[row];
	for (int i = 0; i < row; i++)
	{
		charBoard[i] = new char[column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			charBoard[i][j] = ' ';
		}
	}

	//keeps track of the color of the board under the and, since I cannot print both the ant postion and square color
	boolBoard = new bool*[row];
	for (int i = 0; i < row; i++)
	{
		boolBoard[i] = new bool[column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			boolBoard[i][j] = true;
		}
	}
}

void AntBoard::makeMove(Ant *ant, int steps)
{
	int moves = 0;
		
	while (moves <= steps)
	{
		//I use the boolboard so I don't have to remove the ant and check the color of the board
		//This one checks to see if the board is white
		if (boolBoard[ant->cRow()][ant->cColumn()] == true)
		{
			switch (ant->currentOrientation())
			{
			case Up:
				ant->changeOrientation(Right);
				if (ant->cColumn() == maxColumn)
				{
					ant->changeOrientation(Left);
					break;
				}
				charBoard[ant->cRow()][ant->cColumn() + 1] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = '#';
				boolBoard[ant->cRow()][ant->cColumn()] = false;
				ant->updateLocation(ant->cRow(), ant->cColumn() + 1);
				break;
			case Right:
				ant->changeOrientation(Down);
				if (ant->cRow() == maxRow)
				{
					ant->changeOrientation(Up);
					break;
				}
				charBoard[ant->cRow() + 1][ant->cColumn()] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = '#';
				boolBoard[ant->cRow()][ant->cColumn()] = false;
				ant->updateLocation(ant->cRow() + 1, ant->cColumn());
				break;
			case Down:
				ant->changeOrientation(Left);
				if (ant->cColumn() == 0)
				{
					ant->changeOrientation(Right);
					break;
				}
				charBoard[ant->cRow()][ant->cColumn() - 1] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = '#';
				boolBoard[ant->cRow()][ant->cColumn()] = false;
				ant->updateLocation(ant->cRow(), ant->cColumn() - 1);
				break;
			case Left:
				ant->changeOrientation(Up);
				if (ant->cRow() == 0)
				{
					ant->changeOrientation(Down);
					break;
				}
				charBoard[ant->cRow() - 1][ant->cColumn()] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = '#';
				boolBoard[ant->cRow()][ant->cColumn()] = false;
				ant->updateLocation(ant->cRow() - 1, ant->cColumn());
				break;
			}
			moves++;
			printBoard();
			std::cout << std::endl;
		}
		//this one is checking to see if the board is gray
		else if (boolBoard[ant->cRow()][ant->cColumn()] == false)
		{
			switch (ant->currentOrientation())
			{
			case Up:
				ant->changeOrientation(Left);
				if (ant->cColumn() == 0)
				{
					ant->changeOrientation(Right);
					break;
				}
				charBoard[ant->cRow()][ant->cColumn() - 1] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = ' ';
				boolBoard[ant->cRow()][ant->cColumn()] = true;
				ant->updateLocation(ant->cRow(), ant->cColumn() - 1);
				break;
			case Left:
				ant->changeOrientation(Down);
				if (ant->cRow() == maxRow)
				{
					ant->changeOrientation(Up);
					break;
				}
				charBoard[ant->cRow() + 1][ant->cColumn()] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = ' ';
				boolBoard[ant->cRow()][ant->cColumn()] = true;
				ant->updateLocation(ant->cRow() + 1, ant->cColumn());
				break;
			case Down:
				ant->changeOrientation(Right);
				if (ant->cColumn() == maxColumn)
				{
					ant->changeOrientation(Left);
					break;
				}
				charBoard[ant->cRow()][ant->cColumn() + 1] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = ' ';
				boolBoard[ant->cRow()][ant->cColumn()] = true;
				ant->updateLocation(ant->cRow(), ant->cColumn() + 1);
				break;
			case Right:
				ant->changeOrientation(Up);
				charBoard[ant->cRow() - 1][ant->cColumn()] = '*';
				charBoard[ant->cRow()][ant->cColumn()] = ' ';
				boolBoard[ant->cRow()][ant->cColumn()] = true;
				ant->updateLocation(ant->cRow() - 1, ant->cColumn());
				break;
			}
			moves++;
			printBoard();
			std::cout << std::endl;
		}
	}
}

void AntBoard::printBoard()
{
	//std::cout << std::setw(maxRow) << std::setfill('-') << std::endl;	
	for (int i = 0; i < maxRow; i++)
	{
		std::cout << '|';
		for (int j = 0; j < maxColumn; j++)
		{
			std::cout << charBoard[i][j];
		}
		std::cout << '|' << std::endl;
	}
	//std::cout << std::setw(maxRow) << std::setfill('_') << std::endl;
}

AntBoard::~AntBoard()
{
	for (int i = 0; i < maxRow; i++)
	{
		delete[] charBoard[i];
	}
	delete[] charBoard;

	for (int i = 0; i < maxRow; i++)
	{
		delete[] boolBoard[i];
	}
	delete[] boolBoard;
}
