#include "nodeQueue.h"

nodeQueue::nodeQueue()
{
	element = "";
	next = NULL;
}

nodeQueue::~nodeQueue()
{
}

string nodeQueue::getElement()
{
	return element;
}
void nodeQueue::setElement(string givenElement)
{
	element = givenElement;
}
nodeQueue* nodeQueue::getNext()
{
	return next;
}
void nodeQueue::setNext(nodeQueue* givenNext)
{
	next = givenNext;
}