/*********************************************************************
** Program name: menu.cpp
** Author: Christopher Gundlach
** Date: 10/07/18
** Description: This is the menu function. It takes the users input to create the board, place the ant and run the program.
*********************************************************************/

#include "menu.hpp"
#include "validator.hpp"
#include "AntBoard.hpp"
#include "Ant.hpp"
#include<iostream>
#include<string>
#include<cctype>

void menu()
{
	bool menuRepeater = true;
	int menuChoice = 0;
	int rows = 0;
	int columns = 0;
	int steps = 0;
	int startRow = 0;
	int startColumn = 0;
	Ant ant;
	AntBoard aBoard;
	//initial menu for the program
	std::cout << "Please enter your choice." << std::endl;
	std::cout << "1. Start Langton's Ant simulation" << std::endl;
	std::cout << "2. Quit" << std::endl;
	menuValidator(menuChoice);

	//enacts the menu choice
	while (menuRepeater)
	{
		switch (menuChoice)
		{
		case 1:
			//sets up all the board and ant variables
			std::cout << "Please choose the number of rows in the board. 2 or more." << std::endl;
			boardValidator(rows);
			std::cout << "There will be " << rows << " rows." << std::endl;
			std::cout << "Please choose the number of columns in the board. 2 or more." << std::endl;
			boardValidator(columns);
			std::cout << "There will be " << columns << " columns." << std::endl;
			aBoard.createBoard(rows, columns);
			std::cout << "Please select the number of steps for the ant to go through." << std::endl;
			intValidator(steps);
			std::cout << "There will be " << steps << " steps." << std::endl;
			std::cout << "Please select the starting row of the ant." << std::endl;
			rowValidator(startRow, rows);
			std::cout << "The ant row will be the " << startRow + 1 << " row." << std::endl;
			std::cout << "Please select the starting column of the ant." << std::endl;
			columnValidator(startColumn, columns);
			std::cout << "The ant column will be the " << startColumn + 1 << " column." << std::endl;
			ant.updateLocation(startRow, startColumn);
			ant.changeOrientation(Left);			
			aBoard.makeMove(&ant, steps);
			std::cout << "Please enter your choice." << std::endl;
			std::cout << "1. Start Langton's Ant simulation" << std::endl;
			std::cout << "2. Quit" << std::endl;
			//repeats to menu for multiple runs of program
			menuValidator(menuChoice);
			break;
		case 2:
			//ends the program
			menuRepeater = false;
			break;
		}
	}


}
