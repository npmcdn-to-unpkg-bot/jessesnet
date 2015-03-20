#include <iostream>
#include "LinkedList.h"

using namespace DataStructures;
using namespace std;

void reverse(LinkedList<int> list);
void iterate(LinkedList<int> list);

int main()
{
	LinkedList<int> list;

	list.insertFirst(1);
	list.insertFirst(12);
	list.insertFirst(14);
	list.insertFirst(23);
	list.insertFirst(2938);
	list.insertFirst(2183);

	// iterate(list);
	// reverse(list);
	list.sort();
	list.reset();

	while(list.iterate()) {
		cout << list.read() << "\n";
	};
}

void reverse(LinkedList<int> list)
{
	list.reset();

	while(list.reverse()) {
		cout << list.read() << "\n";
	}	
}

void iterate(LinkedList<int> list)
{
	while(list.iterate()) {
		cout << list.read() << "\n";
	};

	list.reset();

	while(list.iterate()) {
		cout << list.read() << "\n";
	};
		
	cout << "Single : " << list.reset()->read() << "\n";
}