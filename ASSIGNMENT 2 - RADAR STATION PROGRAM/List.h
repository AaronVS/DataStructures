#ifndef LIST_H
#define LIST_H

#include "Session.h"
#include "nodeList.h"

using namespace std;

typedef nodeList* positionList;

class list 
{
	private:
		positionList header;

	public:
		list();
		~list();
		void insert(Session session, positionList pos);
		void remove(positionList pos);
		Session retrieve(positionList pos);
		positionList next(positionList pos);
		positionList previous(positionList pos);
		void makenullList();
		bool isEmptyList();
		positionList getHeader();
		stack getStackObjects();
};

#endif