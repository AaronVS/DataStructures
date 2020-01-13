#include "nodeHash.h"

nodeHash::nodeHash() 
{
	key = "";
	next = NULL;
	object = *new FlyingObject();
}

nodeHash::~nodeHash()
{

}

string nodeHash::getKey()
{
	return key;
}

void nodeHash::setKey(string givenKey)
{
	key = givenKey;
}

FlyingObject nodeHash::getObject()
{
	return object;
}

void nodeHash::setObject(FlyingObject givenObject)
{
	object = givenObject;
}

nodeHash* nodeHash::getNext()
{
	return next;
}

void nodeHash::setNext(nodeHash* givenNext)
{
	next = givenNext;
}