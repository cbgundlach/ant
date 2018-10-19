/*********************************************************************
** Program name: Ant.cpp
** Author: Christopher Gundlach
** Date: 10/07/18
** Description: This is the header file for the Ant class. It sets the methods to return the ant's 
				current locations as well as change the location and orientation
*********************************************************************/

#include "Ant.hpp"

Ant::Ant(){}

int Ant::cRow()
{
	return currentRow;
}

int Ant::cColumn()
{
	return currentColumn;
}

void Ant::updateLocation(int row, int column)
{
	currentRow = row;
	currentColumn = column;
}

Direction Ant::currentOrientation()
{
	return orientation;
}

void Ant::changeOrientation(Direction dir)
{
	orientation = dir;
}
