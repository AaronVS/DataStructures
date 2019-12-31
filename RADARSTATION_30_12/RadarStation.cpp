#include "RadarStation.h"
#include "Menu.h"

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
				cout << "Exception occured";
			}
			break;
		case 2:
			try
			{
				option2();
			}
			catch (...)
			{
				cout << "Exception occured";
			}
			break;
		case 3:
			try
			{
				option3();
			}
		catch (...)
			{
				cout << "Exception occured";
			}
			break;
		case 4:
			try
			{
				option4();
			}
			catch (...)
			{
				cout << "Exception occured";
			}
			break;
		case 5:
			try
			{
				option5();
			}
			catch (...)
			{
				cout << "Exception occured";
			}
			break;
		case 6:
			try
			{
				option6();
			}
			catch (...)
			{
				cout << "Exception occured";
			}
			break;
		case 7:
			try
			{
				option7();
			}
			catch (...)
			{
				cout << "Exception occured";
			}
			break;
		default:
			break;
	}
}

void RadarStation::option1()																// Run a simulation session
{																				
	//printOption1(true);

	lastSession = lastSession.createSession();												// Initializes a new sesion.
	lastSession.createStack();																// Creates a new stack of objects.
	listOfSessions.insert(lastSession, listOfSessions.getHeader());							// Sesion inserted in list.

	printOption1(false);
}

void RadarStation::option2()																// Print the content of queues Q1 to Q5
{																							
	cout << "Plate 1: " << lastSession.stringQueue(lastSession.getPlate1Queue()) << endl;	// Prints the queue	
	cout << "Number of elements: " << lastSession.getPlate1Queue().getSize() << endl;		// Prints the size of the queue

	cout << "Plate 2: " << lastSession.stringQueue(lastSession.getPlate2Queue()) << endl;
	cout << "Number of elements: " << lastSession.getPlate2Queue().getSize() << endl;

	cout << "Plate 3: " << lastSession.stringQueue(lastSession.getPlate3Queue()) << endl;
	cout << "Number of elements: " << lastSession.getPlate3Queue().getSize() << endl;

	cout << "Plate 4: " << lastSession.stringQueue(lastSession.getPlate4Queue()) << endl;
	cout << "Number of elements: " << lastSession.getPlate4Queue().getSize() << endl;

	cout << "Plate 5: " << lastSession.stringQueue(lastSession.getPlate5Queue()) << endl;
	cout << "Number of elements: " << lastSession.getPlate5Queue().getSize() << endl;
}

void RadarStation::option3()																// Print the content of queues Type and Size
{																
	cout << "Types queue: " << lastSession.stringQueue(lastSession.getTypeQueue()) << endl;
	cout << "Sizes queue: " << lastSession.stringQueue(lastSession.getSizeQueue()) << endl;
}

void RadarStation::option4()
{																//Search for the plates with the given number
	string plateNumbers = "";
	int x = 0;
	queue auxPlatesQueue;

	cout << "Enter the number to be searched: ";
	cin >> plateNumbers;														// Reads the "xxx" string (x = 0-9)
	cout << endl;


	auxPlatesQueue = lastSession.getPlatesByNumber(plateNumbers);						// Gets a queue with the plates that start with the given numbers "xxx??"

	while (!auxPlatesQueue.isEmptyQueue())
	{											// Prints the plates in columns of 7
		if (x < 6)
		{
			cout << "| " << auxPlatesQueue.dequeue() << " ";
			x++;
		}
		else
		{
			cout << "| " << auxPlatesQueue.dequeue() << " |" << endl;
			x = 0;
		}
	}
}

void RadarStation::option5()																
{
	printTable(true);
}

void RadarStation::option6()																
{
	
}

void RadarStation::option7()																
{
	
}

void RadarStation::printPlateQueues()
{
	cout << "Number of elements Q1: " + lastSession.getPlate1Queue().getSize() << endl;
	cout << "Number of elements Q2: " + lastSession.getPlate2Queue().getSize() << endl;
	cout << "Number of elements Q3: " + lastSession.getPlate3Queue().getSize() << endl;
	cout << "Number of elements Q4: " + lastSession.getPlate4Queue().getSize() << endl;
	cout << "Number of elements Q5: " + lastSession.getPlate5Queue().getSize() << endl;
}

void RadarStation::printOption1(bool before)
{
	if (before)
	{
		cout << "Before the session: " << endl;
		printPlateQueues();

	}
	else
	{
		cout << "After the session: " << endl;
		printPlateQueues();

		cout << "Number of Tiny-Superlopez-from Surprise: " << lastSession.getNumberSTS() << endl;
		cout << "Time for creation and insertion: " << lastSession.getTimeAverage() << endl;
		cout << "Time for whole operation: " << lastSession.getTimeOp() << endl;
	}
}

void RadarStation::printTable(bool hashTable)
{
	int x = 1;
	if (hashTable)
	{
		cout << "Statistics - Hash Table \n " << endl;
		cout << "			Drone		Plane		Bird		Superlopez	UFO		Ghost		Flying Rock" << endl;
		cout << "Huge			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Big			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Medium			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Small			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Tiny			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "\nTime:\n" << endl;
	}
	else
	{
		cout << "Statistics - List of Stacks \n " << endl;
		cout << "			Drone		Plane		Bird		Superlopez	UFO		Ghost		Flying Rock" << endl;
		cout << "Huge			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Big			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Medium			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Small			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "Tiny			" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << "		" << x << endl;
		cout << "\nTime:\n" << endl;
	}
}