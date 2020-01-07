#ifndef NODEHASH_H
#define NODEHASH_H
#include <iostream>
#include "FlyingObject.h"

using namespace std;

class nodeHash
{
public:
	string key;
	nodeHash* next;
	FlyingObject object;
public:
	nodeHash();
	~nodeHash();
};


#endif
