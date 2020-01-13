#include "nodeList.h"

nodeList::nodeList()
{
	sn = *new Session();
	next = NULL;
	previous = NULL;
}

nodeList::~nodeList()
{
}

Session nodeList::getSession()
{
	return sn;
}

void nodeList::setSession(Session givenSession)
{
	sn = givenSession;
}

nodeList* nodeList::getNext()
{
	return next;
}

void nodeList::setNext(nodeList* givenNext)
{
	next = givenNext;
}

nodeList* nodeList::getPrevious()
{
	return previous;
}

void nodeList::setPrevious(nodeList* givenPrevious)
{
	previous = givenPrevious;
}