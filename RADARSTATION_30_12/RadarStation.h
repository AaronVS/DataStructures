#ifndef INTERFACE_H
#define INTERFACE_H

#include "Session.h"
#include "List.h"

using namespace std;

class RadarStation {
	list listOfSessions;
	int contador;
	Session lastSession;

	public:
		int runRadar();
		void optionSwitch(int chosenOption);
		void option1();
		void option2();
		void option3();
		void option4();
		void option5();
		void option6();
		void option7();
		void printPlateQueues();
		void printOption1(bool before);
		void printTable(bool hashTable);
	};


#endif

