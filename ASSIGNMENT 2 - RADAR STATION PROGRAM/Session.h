#ifndef SESSION_H
#define SESSION_H

#include "Stack.h"
#include "Hash.h"

class Session {
	stack stackObjects;
	int numberObjects;
	int numberSTS;
	double timeOp;
	double timeAverage;

	queue typeQueue;
	queue sizeQueue;
	queue originQueue;
	queue plate1Queue;
	queue plate2Queue;
	queue plate3Queue;
	queue plate4Queue;
	queue plate5Queue;

	hashStructure hashSt;

	private: 
		static const int typeArraySize = 7;
		static const int sizeArraySize = 5;
		static const int originArraySize = 11;
		static const int plate1ArraySize = 11;
		static const int plate2ArraySize = 17;
		static const int plate3ArraySize = 23;
		static const int plate4ArraySize = 26;
		static const int plate5ArraySize = 32;

	public:
		Session();
		~Session();
		void createStack();
		FlyingObject randFO();
		queue CreateQueueFromArray(string a[], int size);
		queue getPlatesByNumber(string numbers);
		stack getStObject();
		int getNumberObjects();
		int getNumberSTS();
		double getTimeOp();
		double getTimeAverage();
		string stringQueue(queue givenQueue);
		int getSizeGivenQueue(queue givenQueue);
		void printPlatesByNumberStack(string numbers);
		void printPlatesByNumberHash(string numbers);
		void printFlyingObjectsStack(string type, string size, string origin, string plate);
		void printFlyingObjectsHash(string type, string size, string origin, string plate);
		int countFlyingObjectsStack(string type, string size, string origin);
		int countFlyingObjectsHash(string type, string size, string origin);
		void printAllFlyingObjectsStack();
		void printAllFlyingObjectsHash();
		queue getTypeQueue();
		queue getSizeQueue();
		queue getOriginQueue();
		queue getPlate1Queue();
		queue getPlate2Queue();
		queue getPlate3Queue();
		queue getPlate4Queue();
		queue getPlate5Queue();
		hashStructure getHashStructure();
};


#endif 

