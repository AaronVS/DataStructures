#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "Table.h"

using namespace std;

table::table()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			tableFO[i][j] = 0;
		}
	}
}

table::~table()
{
}

void table::printTable(bool hash, Session givenSession)
{
	unsigned t0, t1;
	int x = 1;
	

	if (hash)																// Prints data from Hash structure
	{
		t0 = clock();														// Start of the operation (time = 0).

		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Statistics - Hash Table Data \n " << endl;
		cout << "			Drone		Plane		Bird		Superlopez	UFO		Ghost		Flying Rock" << endl;
		cout << "Huge			" << givenSession.countFlyingObjectsHash("Drone", "Huge","-1") << "		" << givenSession.countFlyingObjectsHash("Plane", "Huge", "-1") << "		" << givenSession.countFlyingObjectsHash("Bird", "Huge", "-1") << "		" << givenSession.countFlyingObjectsHash("Superlopez", "Huge", "-1") << "		" << givenSession.countFlyingObjectsHash("UFO", "Huge", "-1") << "		" << givenSession.countFlyingObjectsHash("Ghost", "Huge", "-1") << "		" << givenSession.countFlyingObjectsHash("FlyingRock", "Huge", "-1") << endl;
		cout << "Big			" << givenSession.countFlyingObjectsHash("Drone", "Big", "-1") << "		" << givenSession.countFlyingObjectsHash("Plane", "Big", "-1") << "		" << givenSession.countFlyingObjectsHash("Bird", "Big", "-1") << "		" << givenSession.countFlyingObjectsHash("Superlopez", "Big", "-1") << "		" << givenSession.countFlyingObjectsHash("UFO", "Big", "-1") << "		" << givenSession.countFlyingObjectsHash("Ghost", "Big", "-1") << "		" << givenSession.countFlyingObjectsHash("FlyingRock", "Big", "-1") << endl;
		cout << "Medium			" << givenSession.countFlyingObjectsHash("Drone", "Medium", "-1") << "		" << givenSession.countFlyingObjectsHash("Plane", "Medium", "-1") << "		" << givenSession.countFlyingObjectsHash("Bird", "Medium", "-1") << "		" << givenSession.countFlyingObjectsHash("Superlopez", "Medium", "-1") << "		" << givenSession.countFlyingObjectsHash("UFO", "Medium", "-1") << "		" << givenSession.countFlyingObjectsHash("Ghost", "Medium", "-1") << "		" << givenSession.countFlyingObjectsHash("FlyingRock", "Medium", "-1") << endl;
		cout << "Small			" << givenSession.countFlyingObjectsHash("Drone", "Small", "-1") << "		" << givenSession.countFlyingObjectsHash("Plane", "Small", "-1") << "		" << givenSession.countFlyingObjectsHash("Bird", "Small", "-1") << "		" << givenSession.countFlyingObjectsHash("Superlopez", "Small", "-1") << "		" << givenSession.countFlyingObjectsHash("UFO", "Small", "-1") << "		" << givenSession.countFlyingObjectsHash("Ghost", "Small", "-1") << "		" << givenSession.countFlyingObjectsHash("FlyingRock", "Small", "-1") << endl;
		cout << "Tiny			" << givenSession.countFlyingObjectsHash("Drone", "Tiny", "-1") << "		" << givenSession.countFlyingObjectsHash("Plane", "Tiny", "-1") << "		" << givenSession.countFlyingObjectsHash("Bird", "Tiny", "-1") << "		" << givenSession.countFlyingObjectsHash("Superlopez", "Tiny", "-1") << "		" << givenSession.countFlyingObjectsHash("UFO", "Tiny", "-1") << "		" << givenSession.countFlyingObjectsHash("Ghost", "Tiny", "-1") << "		" << givenSession.countFlyingObjectsHash("FlyingRock", "Tiny", "-1") << endl;
		
		t1 = clock();														// End of the operation duration.

		cout << "\nTime:" << (double(t1 - t0) / CLOCKS_PER_SEC) << endl;	// Print of the total time 
	}
	else																	// Prints data from Stack structure.
	{
		t0 = clock();														// Start of the operation (time = 0).
		
		getValuesTable(givenSession);										// Gets the values from stack data from the last session and initializes the table with them.

		cout << "\nStatistics - Stack Data \n " << endl;
		cout << "			Drone		Plane		Bird		Superlopez	UFO		Ghost		Flying Rock" << endl;
		cout << "Huge			" << tableFO[0][0] << "		" << tableFO[0][1] << "		" << tableFO[0][2] << "		" << tableFO[0][3] << "		" << tableFO[0][4] << "		" << tableFO[0][5] << "		" << tableFO[0][6] << endl;
		cout << "Big			" << tableFO[1][0] << "		" << tableFO[1][1] << "		" << tableFO[1][2] << "		" << tableFO[1][3] << "		" << tableFO[1][4] << "		" << tableFO[1][5] << "		" << tableFO[1][6] << endl;
		cout << "Medium			" << tableFO[2][0] << "		" << tableFO[2][1] << "		" << tableFO[2][2] << "		" << tableFO[2][3] << "		" << tableFO[2][4] << "		" << tableFO[2][5] << "		" << tableFO[2][6] << endl;
		cout << "Small			" << tableFO[3][0] << "		" << tableFO[3][1] << "		" << tableFO[3][2] << "		" << tableFO[3][3] << "		" << tableFO[3][4] << "		" << tableFO[3][5] << "		" << tableFO[3][6] << endl;
		cout << "Tiny			" << tableFO[4][0] << "		" << tableFO[4][1] << "		" << tableFO[4][2] << "		" << tableFO[4][3] << "		" << tableFO[4][4] << "		" << tableFO[4][5] << "		" << tableFO[4][6] << endl;
		
		t1 = clock();														// End of the operation duration.

		cout << "\nTime:" << (double(t1 - t0) / CLOCKS_PER_SEC) << endl;	// Print of the total time
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl << endl;

	}
}

void table::getValuesTable(Session givenSession)
{
	int row, column;
	string size, type;
	stack auxStackOfObjects = *new stack();
	FlyingObject currentFlyingObject = *new FlyingObject();

	auxStackOfObjects = givenSession.getStObject();

	while (!auxStackOfObjects.isEmptyStack())						// Goes through the whole stack
	{
		currentFlyingObject = auxStackOfObjects.pop();

		size = currentFlyingObject.getSize();						// Gets the size of the popped element
		type = currentFlyingObject.getType();						// Gets the type of the popped element

		row = getRowTable(size);									// Gets the row of the table by the given size
		column = getColumnTable(type);								// Gets the column of the table by the given type

		tableFO[row][column]++;										// Adds +1 to the value in the table in the given row and column 
	}
}

int table::getColumnTable(string type)
{
	int column = 0;
	if (type == "Drone")
	{
		column = 0;
	}
	else if (type == "Plane")
	{
		column = 1;
	}
	else if (type == "Bird")
	{
		column = 2;
	}
	else if (type == "Superlopez")
	{
		column = 3;
	}
	else if (type == "UFO")
	{
		column = 4;
	}
	else if (type == "Ghost")
	{
		column = 5;
	}
	else
	{
		column = 6;
	}
	return column;
}

int table::getRowTable(string size)
{
	int row = 0;
	if (size == "Huge")
	{
		row = 0;
	}
	else if (size == "Big")
	{
		row = 1;
	}
	else if (size == "Medium")
	{
		row = 2;
	}
	else if (size == "Small")
	{
		row = 3;
	}
	else
	{
		row = 4;
	}
	return row;
}
