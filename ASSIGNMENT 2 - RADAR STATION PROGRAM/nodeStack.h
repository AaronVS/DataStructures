#ifndef NODESTACK_H
#define NODESTACK_H

#include "FlyingObject.h"

using namespace std;

class nodeStack
{
	private:
		FlyingObject object;
		nodeStack* next;
	
	public:
		nodeStack();
		~nodeStack();
		FlyingObject getObject();
		void setObject(FlyingObject givenObject);
		nodeStack* getNext();
		void setNext(nodeStack* givenNext);
};

#endif