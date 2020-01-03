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
		RadarStation();
		~RadarStation();
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
		void printOption4(queue queueToPrint);
		void printOption7();
		void printTable(bool hashTable, int tableValues[5][7]);
		void getValuesTable(int table[5][7]);
		int getColumnTable(string type);
		int getRowTable(string size);
		void initTable(int table[5][7]);
	};


#endif

