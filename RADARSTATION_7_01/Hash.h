#ifndef HASH_H
#define HASH_H

#include "nodeHash.h"
#include "FlyingObject.h"

using namespace std;

class hashStructure
{
public:
	nodeHash* hashTable[1000];

public:
	hashStructure();
	~hashStructure();
	int hashFunction(string plate);
	void insertFlyingObject(FlyingObject givenObject, string plate);
	FlyingObject searchFlyingObject(string plate, string type, string size, string origin, int objectAppearance);
};

#endif