#ifndef HASH_H
#define HASH_H

#include "nodeHash.h"
#include "FlyingObject.h"

using namespace std;

class hashStructure
{
private: static const int tableSize = 1000;
public:
	nodeHash *hashTable[tableSize];

public:
	hashStructure();
	~hashStructure();
	int hashFunction(string plate);
	void insert(FlyingObject givenObject, string plate);
};

#endif