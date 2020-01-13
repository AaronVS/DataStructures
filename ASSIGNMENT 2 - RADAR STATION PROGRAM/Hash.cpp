#include "Hash.h"
using namespace std;

hashStructure::hashStructure()
{
	for (int i = 0; i < 1000; i++)
	{
		hashTable[i] = new nodeHash();
	}
}

hashStructure::~hashStructure()
{

}

int hashStructure::hashFunction(string plate)
{
	int firstNumber = (int)plate.at(0) - 48;			//ASCII
	int secondNumber = (int)plate.at(1) - 48;			//ASCII
	int thirdNumber = (int)plate.at(2) - 48;			//ASCII

	int index = ( firstNumber * 100 ) + ( secondNumber * 10 ) + thirdNumber;

	return index;
}

void hashStructure::insert(FlyingObject givenObject, string plate)
{
	int index = hashFunction(plate);

	if (hashTable[index]->getKey() == "")
	{
		hashTable[index]->setKey(plate);
		hashTable[index]->setObject(givenObject);
	}
	else
	{
		nodeHash *linkedElement = hashTable[index];
		nodeHash *auxPtr = new nodeHash();

		auxPtr->setKey(plate);
		auxPtr->setObject(givenObject);
		auxPtr->setNext(NULL);

		while (linkedElement->getNext() != NULL)
		{
			linkedElement = linkedElement->getNext();
		}
		linkedElement->setNext(auxPtr);
	}
}

nodeHash* hashStructure::getNodeAtIndex(int index)
{
	return hashTable[index];
}