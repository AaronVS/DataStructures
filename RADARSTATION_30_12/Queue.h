#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "nodeQueue.h"

using namespace std;



typedef nodeQueue* positionQueue;

class queue 
{
	positionQueue fr;
	positionQueue rear;
	int size;

	public:
		string dequeue();
		void enqueue(string element);
		string front();
		void makenullQueue();
		bool isEmptyQueue();
		int getSize();
};

#endif

