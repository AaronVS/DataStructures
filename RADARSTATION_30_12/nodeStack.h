#ifndef NODESTACK_H
#define NODESTACK_H

#include "FlyingObject.h"

using namespace std;

class nodeStack
{
	public:
		FlyingObject object;
		nodeStack* next;
};

#endif