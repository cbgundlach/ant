/*********************************************************************
** Program name: Ant.hpp
** Author: Christopher Gundlach
** Date: 10/07/18
** Description: This is the Ant class. It has an enum to keep track of the ant's orientation
				and creates the private variables for the an't location and direction. It also creats the public methods
				to change those variables and return location.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum Direction{Up, Right, Down, Left};

class Ant
{
private:
	int currentRow;
	int currentColumn;
	Direction orientation;
public:
	Ant();
	int cRow();
	int cColumn();
	void updateLocation(int, int);
	Direction currentOrientation();
	void changeOrientation(Direction);

};

#endif // !ANT_HPP

