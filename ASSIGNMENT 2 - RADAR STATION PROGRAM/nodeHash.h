#ifndef NODEHASH_H
#define NODEHASH_H
#include <iostream>
#include "FlyingObject.h"

using namespace std;

class nodeHash
{
	private:
		string key;
		FlyingObject object;
		nodeHash* next;

	public:
		nodeHash();
		~nodeHash();
		string getKey();
		void setKey(string givenKey);
		FlyingObject getObject();
		void setObject(FlyingObject givenObject);
		nodeHash* getNext();
		void setNext(nodeHash* givenNext);
};


#endif
