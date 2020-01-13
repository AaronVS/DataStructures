#ifndef NODELIST_H
#define NODELIST_H
#include <iostream>
#include "Session.h"

class nodeList
{
	private:
		Session sn;
		nodeList* next;
		nodeList* previous;

	public:
		nodeList();
		~nodeList();
		Session getSession();
		void setSession(Session givenSession);
		nodeList* getNext();
		void setNext(nodeList* givenNext);
		nodeList* getPrevious();
		void setPrevious(nodeList* givenPrevious);
};


#endif
