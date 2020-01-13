#include "Stack.h"

stack::stack()
{
	root = new nodeStack();
}

stack::~stack()
{

}

FlyingObject stack::pop() 
{
	FlyingObject element;
	if (isEmptyStack())
	{
		throw;
	}
	else 
	{
		positionStack temp = root;
		root = root->getNext();
		element = temp->getObject();

	}
	return element;
}

void stack::push(FlyingObject element) 
{
	positionStack pos = new nodeStack();
	pos->setObject(element);
	pos->setNext(NULL);
	positionStack temp = root;
	root = pos;
	root->setNext(temp); 
}

FlyingObject stack::top() 
{
	return root->getObject();
}

void stack::makenullStack()
{
	while (root != NULL)
	{
		pop();
	}
}

bool stack::isEmptyStack()
{
	return root->getNext() == NULL && root->getObject().getPlate() == "";
}

FlyingObject stack::getObject() 
{
	return root->getObject();
}
