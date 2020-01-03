#include "RadarStation.h"
#include "Menu.h"

RadarStation::RadarStation()
{
	listOfSessions = *new list();
	contador = 0;
	lastSession = *new Session();
}

RadarStation::~RadarStation()
{
}

int RadarStation::runRadar()
{
	Menu menuInterface;
	int chosenOption;

	chosenOption = menuInterface.menu();
	optionSwitch(chosenOption);

	return chosenOption;
}

void RadarStation::optionSwitch(int chosenOption) 
{
	switch (chosenOption)
	{
		case 1:
			try
			{
				option1();
			}
			catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		case 2:
			try
			{
				option2();
			}
			catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		case 3:
			try
			{
				option3();
			}
		catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		case 4:
			try
			{
				option4();
			}
			catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		case 5:
			try
			{
				option5();
			}
			catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		case 6:
			try
			{
				option6();
			}
			catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		case 7:
			try
			{
				option7();
			}
			catch (...)
			{
				cout << "Exception occured \n";
			}
			break;
		default:
			break;
	}
}

void RadarStation::option1()																// Run a simulation session
{	
	lastSession = *new Session();															// Initializes a new sesion.

	printOption1(true);

	lastSession.createStack();																// Creates a new stack of objects.
	listOfSessions.insert(lastSession, listOfSessions.getHeader());							// Sesion inserted in list.

	printOption1(false);

}

void RadarStation::option2()																					// Print the content of queues Q1 to Q5
{																							
	cout << "Plate 1: " << lastSession.stringQueue(lastSession.getPlate1Queue());								// Prints the queue	
	cout << "Number of elements: " << lastSession.getSizeGivenQueue(lastSession.getPlate1Queue()) << endl << endl;		// Prints the size of the queue

	cout << "Plate 2: " << lastSession.stringQueue(lastSession.getPlate2Queue());
	cout << "Number of elements: " << lastSession.getSizeGivenQueue(lastSession.getPlate2Queue()) << endl << endl;

	cout << "Plate 3: " << lastSession.stringQueue(lastSession.getPlate3Queue());
	cout << "Number of elements: " << lastSession.getSizeGivenQueue(lastSession.getPlate3Queue()) << endl << endl;

	cout << "Plate 4: " << lastSession.stringQueue(lastSession.getPlate4Queue());
	cout << "Number of elements: " << lastSession.getSizeGivenQueue(lastSession.getPlate4Queue()) << endl << endl;

	cout << "Plate 5: " << lastSession.stringQueue(lastSession.getPlate5Queue());
	cout << "Number of elements: " << lastSession.getSizeGivenQueue(lastSession.getPlate5Queue()) << endl << endl;
}

void RadarStation::option3()																// Print the content of queues Type and Size
{																
	cout << "Type queue: " << lastSession.stringQueue(lastSession.getTypeQueue()) << endl;
	cout << "Size queue: " << lastSession.stringQueue(lastSession.getSizeQueue()) << endl;
}

void RadarStation::option4()
{																									//Search for the plates with the given number
	string plateNumbers;
	queue auxPlatesQueue = *new queue();

	cout << "Enter the number to be searched ( xxx where x = 0-9 ): ";
	cin >> plateNumbers;																			// Reads the "xxx" string (x = 0-9)
	cout << endl;

	auxPlatesQueue = lastSession.getPlatesByNumber(plateNumbers);									// Gets a queue with the plates that start with the given numbers "xxx??"

	printOption4(auxPlatesQueue);
}

void RadarStation::option5()																
{
	int table[5][7];

	initTable(table);
	getValuesTable(table);

	printTable(true, table);
	printTable(false, table);
}

void RadarStation::option6()																
{
	
}

void RadarStation::option7()																
{
	printOption7();
}

void RadarStation::printPlateQueues()
{
	cout << "	Number of elements plate queue 1: " << lastSession.getSizeGivenQueue(lastSession.getPlate1Queue()) << endl;
	cout << "	Number of elements plate queue 2: " << lastSession.getSizeGivenQueue(lastSession.getPlate2Queue()) << endl;
	cout << "	Number of elements plate queue 3: " << lastSession.getSizeGivenQueue(lastSession.getPlate3Queue()) << endl;
	cout << "	Number of elements plate queue 4: " << lastSession.getSizeGivenQueue(lastSession.getPlate4Queue()) << endl;
	cout << "	Number of elements plate queue 5: " << lastSession.getSizeGivenQueue(lastSession.getPlate5Queue()) << endl;
}

void RadarStation::printOption1(bool before)
{
	if (before)
	{
		cout << "Before the session: \n" << endl;
		printPlateQueues();
	}
	else
	{
		cout << endl << endl;
		cout << "After the session: \n" << endl;
		printPlateQueues();

		cout << "\n	Number of Tiny-Superlopez-from Surprise: " << lastSession.getNumberSTS() << endl;
		cout << "	Time for creation and insertion: " << lastSession.getTimeAverage() << endl;
		cout << "	Time for whole operation: " << lastSession.getTimeOp() << endl << endl;
	}
}

void RadarStation::printOption4(queue queueToPrint)
{
	int column = 0;																				// Used to print the plates in columns of 7.
	while (!queueToPrint.isEmptyQueue())														// Prints the plates in columns of 7.
	{		
		if (column < 6)
		{
			cout << "| " << queueToPrint.dequeue() << " ";
			column++;
		}
		else
		{
			cout << "| " << queueToPrint.dequeue() << " |" << endl;
			column = 0;
		}
		if (queueToPrint.isEmptyQueue())
		{
			cout << "|" << endl << endl;
		}
	}
}

void RadarStation::printOption7() 
{

}

void RadarStation::printTable(bool hashTable, int tableValues[5][7])
{
	int x = 1;
	if (hashTable)
	{
		cout << "Statistics - Hash Table \n " << endl;
		cout << "			Drone		Plane		Bird		Superlopez	UFO		Ghost		Flying Rock" << endl;
		cout << "Huge			" << tableValues[0][0] << "		" << tableValues[0][1] << "		" << tableValues[0][2] << "		" << tableValues[0][3] << "		" << tableValues[0][4] << "		" << tableValues[0][5] << "		" << tableValues[0][6] << endl;
		cout << "Big			" << tableValues[1][0] << "		" << tableValues[1][1] << "		" << tableValues[1][2] << "		" << tableValues[1][3] << "		" << tableValues[1][4] << "		" << tableValues[1][5] << "		" << tableValues[1][6] << endl;
		cout << "Medium			" << tableValues[2][0] << "		" << tableValues[2][1] << "		" << tableValues[2][2] << "		" << tableValues[2][3] << "		" << tableValues[2][4] << "		" << tableValues[2][5] << "		" << tableValues[2][6] << endl;
		cout << "Small			" << tableValues[3][0] << "		" << tableValues[3][1] << "		" << tableValues[3][2] << "		" << tableValues[3][3] << "		" << tableValues[3][4] << "		" << tableValues[3][5] << "		" << tableValues[3][6] << endl;
		cout << "Tiny			" << tableValues[4][0] << "		" << tableValues[4][1] << "		" << tableValues[4][2] << "		" << tableValues[4][3] << "		" << tableValues[4][4] << "		" << tableValues[4][5] << "		" << tableValues[4][6] << endl;
		cout << "\nTime:\n" << endl;
	}
	else
	{
		cout << "Statistics - List of Stacks \n " << endl;
		cout << "			Drone		Plane		Bird		Superlopez	UFO		Ghost		Flying Rock" << endl;
		cout << "Huge			" << tableValues[0][0] << "		" << tableValues[0][1] << "		" << tableValues[0][2] << "		" << tableValues[0][3] << "		" << tableValues[0][4] << "		" << tableValues[0][5] << "		" << tableValues[0][6] << endl;
		cout << "Big			" << tableValues[1][0] << "		" << tableValues[1][1] << "		" << tableValues[1][2] << "		" << tableValues[1][3] << "		" << tableValues[1][4] << "		" << tableValues[1][5] << "		" << tableValues[1][6] << endl;
		cout << "Medium			" << tableValues[2][0] << "		" << tableValues[2][1] << "		" << tableValues[2][2] << "		" << tableValues[2][3] << "		" << tableValues[2][4] << "		" << tableValues[2][5] << "		" << tableValues[2][6] << endl;
		cout << "Small			" << tableValues[3][0] << "		" << tableValues[3][1] << "		" << tableValues[3][2] << "		" << tableValues[3][3] << "		" << tableValues[3][4] << "		" << tableValues[3][5] << "		" << tableValues[3][6] << endl;
		cout << "Tiny			" << tableValues[4][0] << "		" << tableValues[4][1] << "		" << tableValues[4][2] << "		" << tableValues[4][3] << "		" << tableValues[4][4] << "		" << tableValues[4][5] << "		" << tableValues[4][6] << endl;
		cout << "\nTime:\n" << endl;
	}
}

void RadarStation::getValuesTable(int table[5][7])
{
	int row, column;
	string size, type;
	stack auxStackOfObjects = *new stack();
	FlyingObject currentFlyingObject = *new FlyingObject();

	auxStackOfObjects = lastSession.getStObject();

	while (!auxStackOfObjects.isEmptyStack())
	{
		currentFlyingObject = auxStackOfObjects.pop();

		size = currentFlyingObject.getSize();
		type = currentFlyingObject.getType();

		row = getRowTable(size);
		column = getColumnTable(type);

		table[row][column]++;
	}
}

int RadarStation::getColumnTable(string type)
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

int RadarStation::getRowTable(string size)
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

void RadarStation::initTable(int table[5][7])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			table[i][j] = 0;
		}
	}
}