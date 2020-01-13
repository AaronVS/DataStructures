#include "Queue.h"

queue::queue()
{
	rear = new nodeQueue();
	fr = new nodeQueue();
}

queue::~queue()
{

}

string queue::dequeue()
{
	string element = "";

	if (isEmptyQueue())
	{
		throw;
	}
	else
	{
		positionQueue temp = fr;
		fr = fr->getNext();
		element = temp->getElement();

	}
	
	return element;
}

void queue::enqueue(string element) 
{
	nodeQueue* pos = new nodeQueue();
	pos->setElement(element);
	pos->setNext(NULL);

	if (isEmptyQueue())
	{
		fr = pos;
		rear = pos;
		fr->setNext(rear);
		rear->setNext(NULL);
	}
	else
	{
		positionQueue temp = rear;
		rear = pos;
		temp->setNext(rear);
	}
}

string queue::front() 
{
	return fr->getElement();
}

string queue::rearElement()
{
	return rear->getElement();
}

void queue::makenullQueue()
{
	while (fr != NULL) 
	{
		dequeue();
	}
}

bool queue::isEmptyQueue()
{
	return  fr == NULL || fr->getNext() == NULL && fr->getElement() == "";
}

