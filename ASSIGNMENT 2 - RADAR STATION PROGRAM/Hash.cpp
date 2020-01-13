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

	if (hashTable[index]->key == "")
	{
		hashTable[index]->key = plate;
		hashTable[index]->object = givenObject;
	}
	else
	{
		nodeHash *linkedElement = hashTable[index];
		nodeHash *auxPtr = new nodeHash();

		auxPtr->key = plate;
		auxPtr->object = givenObject;
		auxPtr->next = NULL;

		while (linkedElement->next != NULL)
		{
			linkedElement = linkedElement->next;
		}
		linkedElement->next = auxPtr;
	}
}