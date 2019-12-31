#include "Queue.h"

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
		fr = fr->next;
		element = temp->element;
		delete temp;
	}
	size--;
	return element;
}

void queue::enqueue(string element) 
{
	positionQueue pos = nullptr;
	pos->element = element;
	pos->next = NULL;
	positionQueue temp = rear;
	rear = pos;
	temp->next = rear;
	size++;
}

string queue::front() 
{
	return fr->element;
}

void queue::makenullQueue()
{
	while (fr != NULL) 
	{
		dequeue();
	}
	size = 0;
}

bool queue::isEmptyQueue()
{
	return fr == rear && fr == NULL;
}

int queue::getSize() 
{
	return size;
}
