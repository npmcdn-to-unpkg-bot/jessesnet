#include <iostream>
#include "LinkedList.h"

using namespace DataStructures;
using namespace std;


int main()
{
	LinkedList<int> list;

	list.insertFirst(1);
	list.insertFirst(12);
	list.insertFirst(14);
	list.insertFirst(23);
	list.insertFirst(2183);
	list.insertFirst(2938);
	
	/*
	cout << "SIZE : " << list.size() << "\n";
	
	cout << list.first() << "\n";
	cout << list.last() << "\n";
	*/

	cout << "TEST\n";
	list.test();	
}

