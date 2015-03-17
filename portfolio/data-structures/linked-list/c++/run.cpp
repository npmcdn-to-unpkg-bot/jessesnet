#include <iostream>
#include "LinkedList.h"

using namespace DataStructures;
using namespace std;


int main()
{
	LinkedList<int> list;
	list.insert(1);

	cout << list.element() << "\n";
}

