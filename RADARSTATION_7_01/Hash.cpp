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

	int index = firstNumber + secondNumber + thirdNumber;

	return index;
}

void hashStructure::insertFlyingObject(FlyingObject givenObject, string plate)
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

FlyingObject hashStructure::searchFlyingObject(string plate, string type, string size, string origin, int objectAppearance)
{
	int index = hashFunction(plate);
	FlyingObject searchedFO = *new FlyingObject();

	nodeHash* linkedElement = hashTable[index];

	while (linkedElement->next != NULL)
	{
		if (type == linkedElement->object.getType() || type == "-1")
		{
			if (size == linkedElement->object.getSize() || size == "-1")
			{
				if (origin == linkedElement->object.getOrigin() || origin == "-1")
				{
					if (plate == linkedElement->object.getPlate() || plate == "-1")
					{
						searchedFO = linkedElement->object;
						objectAppearance++;
					}
				}
			}
		}
	}
	return searchedFO;
}
