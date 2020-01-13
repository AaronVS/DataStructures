#include "nodeStack.h"

nodeStack::nodeStack()
{
	object = *new FlyingObject();
	next = NULL;
}

nodeStack::~nodeStack()
{
}

FlyingObject nodeStack::getObject()
{
	return object;
}
void nodeStack::setObject(FlyingObject givenObject)
{
	object = givenObject;
}
nodeStack* nodeStack::getNext()
{
	return next;
}
void nodeStack::setNext(nodeStack* givenNext)
{
	next = givenNext;
}