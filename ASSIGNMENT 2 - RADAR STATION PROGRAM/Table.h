#ifndef TABLE_H
#define TABLE_H

#include "Session.h"

class table
{
	private:
		static const int rowTableSize = 5;					// 5 sizes 
		static const int columnTableSize = 7;				// 7 types
		int tableFO[rowTableSize][columnTableSize];
	public:
		table();
		~table();
		void printTable(bool hash, Session givenSession);
		void getValuesTable(Session givenSession);
		int getColumnTable(string type);
		int getRowTable(string size);
};

#endif
