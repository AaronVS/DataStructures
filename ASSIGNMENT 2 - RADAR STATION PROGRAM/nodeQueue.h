#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include <iostream>

using namespace std;

class nodeQueue
{
	private:
		string element;
		nodeQueue* next;

	public:
		nodeQueue();
		~nodeQueue();
		string getElement();
		void setElement(string givenElement);
		nodeQueue* getNext();
		void setNext(nodeQueue* givenNext);
};

#endif // NODEQUEUE_H