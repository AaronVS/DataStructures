#ifndef FLYINGONBJECT_H
#define FLYINGONBJECT_H

#include "Queue.h"  

using namespace std;

class FlyingObject
{
	private:
		string type;
		string size;
		string origin;
		string plate;
	public:
		FlyingObject();
		~FlyingObject();
		FlyingObject createFlyingObject(string tp, string sz, string og, string plt);
		string getType();
		string getSize();
		string getOrigin();
		string getPlate();
};

#endif
