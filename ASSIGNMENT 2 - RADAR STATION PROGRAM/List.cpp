#include "List.h"

list::list() 
{
	header = new nodeList();
}

list::~list()
{
}
void list::insert(Session ses, positionList pos)
{
	positionList temp = new nodeList();
	if (pos == NULL) 
	{
		throw;
	}
	else if (isEmptyList())
	{
		header->setSession(ses);
	}
	else 
	{
		temp->setSession(ses);
		temp->setNext(pos->getNext());
		temp->setPrevious(pos);
		pos->getNext()->setPrevious(temp);
		pos->setNext(temp);
		pos->setNext(pos);
		temp = pos->getNext();
	}
}
void list::remove(positionList pos)
{
	if (pos == NULL)
	{
		throw;
	}
	if (pos->getNext() != NULL)
	{
		pos->getNext()->setPrevious(pos->getPrevious());
	}
	if (pos->getPrevious() != NULL)
	{
		pos->getPrevious()->setNext(pos->getNext());
	}
	delete(pos);
};

Session list::retrieve(positionList pos)
{
	if (pos == NULL)
	{
		throw;
	};
	return pos->getSession();
}

positionList list::next(positionList pos)
{
	if (pos == NULL)
	{
		throw;
	};
	return pos->getNext();
}
positionList list::previous(positionList pos)
{
	if (pos == NULL)
	{
		throw;
	};
	return pos->getPrevious();
}
void list::makenullList() 
{
	while (isEmptyList())
	{
		remove(header);
	}
}
bool list::isEmptyList()
{
	return header != NULL;
}
positionList list::getHeader()
{
	return header;
}
stack list::getStackObjects() 
{
	return header->getSession().getStObject();
}