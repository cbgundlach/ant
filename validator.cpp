/*********************************************************************
** Program name: validator.cpp
** Author: Christopher Gundlach
** Date: 10/07/18
** Description: These are the validator functions. They cover validation for the menu choice, number of steps, board
				size and ant placement.
*********************************************************************/

#include "validator.hpp"
#include<iostream>
#include<cctype>
#include<sstream>
#include<string>

//validates for the only two menu options
void menuValidator(int &menuInt)
{
	int temp = 0;
	std::string tempStr = "";
	bool wrongInput = false;
	do
	{
		wrongInput = false;
		std::cin >> tempStr;
		for (int i = 0; i < tempStr.length(); i++)
		{
			if (!isdigit(tempStr[i]))
			{
				wrongInput = true;
				std::cout << "Input was not an integer, please try again." << std::endl;
				break;
			}
		}
		std::stringstream ss(tempStr);
		ss >> temp;
		if (temp < 1 || temp > 2)
		{
			wrongInput = true;
			std::cout << "Please input an acceptable integer." << std::endl;
			ss.clear();
			ss.ignore();
		}
	} while (wrongInput);
	
	menuInt = temp;
}

//tests for the number of steps, but doesn't allow a negative number or larger than an int can hold
void intValidator(int &validInt)
{
	int temp = 0;
	std::string tempStr = "";
	bool wrongInput = false;
	do
	{
		wrongInput = false;
		std::cin >> tempStr;
		for (int i = 0; i < tempStr.length(); i++)
		{
			if (!isdigit(tempStr[i]))
			{
				wrongInput = true;
				std::cout << "Input was not an integer, please try again." << std::endl;
				break;
			}
		}
		std::stringstream ss(tempStr);
		ss >> temp;
		if (temp < 0 || temp > 32767)
		{
			wrongInput = true;
			std::cout << "That number is either to high or too low. Please try again." << std::endl;
			ss.clear();
			ss.ignore();
		}
	} while (wrongInput);

	validInt = temp;
}

//Keeps the board from being too small or too large
void boardValidator(int &validSize)
{
	int temp = 0;
	std::string tempStr = "";
	bool wrongInput = false;
	do
	{
		wrongInput = false;
		std::cin >> tempStr;
		for (int i = 0; i < tempStr.length(); i++)
		{
			if (!isdigit(tempStr[i]))
			{
				wrongInput = true;
				std::cout << "Input was not an integer, please try again." << std::endl;
				break;
			}
		}
		std::stringstream ss(tempStr);
		ss >> temp;
		if (temp < 2 || temp > 32767)
		{
			wrongInput = true;
			std::cout << "That number is either to high or too low. Please try again." << std::endl;
			ss.clear();
			ss.ignore();
		}
	} while (wrongInput);

	validSize = temp;
}

//does not allow for a row outside the bounds of the array
void rowValidator(int &validSpot, int row)
{
	int temp = 0;
	std::string tempStr = "";
	bool wrongInput = false;
	do
	{
		wrongInput = false;
		std::cin >> tempStr;
		for (int i = 0; i < tempStr.length(); i++)
		{
			if (!isdigit(tempStr[i]))
			{
				wrongInput = true;
				std::cout << "Input was not an integer, please try again." << std::endl;
				break;
			}
		}
		std::stringstream ss(tempStr);
		ss >> temp;
		if (temp < 0 || temp > row)
		{
			wrongInput = true;
			std::cout << "That number is either to high or too low. Please try again." << std::endl;
			ss.clear();
			ss.ignore();
		}
	} while (wrongInput);

	validSpot = temp - 1;
}

// does not allow for a column position beyond the bounds of the array
void columnValidator(int &validSpot, int column)
{
	int temp = 0;
	std::string tempStr = "";
	bool wrongInput = false;
	do
	{
		wrongInput = false;
		std::cin >> tempStr;
		for (int i = 0; i < tempStr.length(); i++)
		{
			if (!isdigit(tempStr[i]))
			{
				wrongInput = true;
				std::cout << "Input was not an integer, please try again." << std::endl;
				break;
			}
		}
		std::stringstream ss(tempStr);
		ss >> temp;
		if (temp < 0 || temp > column)
		{
			wrongInput = true;
			std::cout << "That number is either to high or too low. Please try again." << std::endl;
			ss.clear();
			ss.ignore();
		}
	} while (wrongInput);

	validSpot = temp - 1;
}
