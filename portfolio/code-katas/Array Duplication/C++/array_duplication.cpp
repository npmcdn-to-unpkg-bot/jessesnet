#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 array_duplication.cpp -o array_duplication
// ./array_duplication

int array[] = {12342,923422,234278,23429,23421,242342,242342};

int ohN()
{
	long largest = 0;

	for (int val : array) {
		if (val > largest) {
			largest = val;
		}
	}

	// int* found = new int[largest]; // if allocation fails, an exception is thrown 
	int *found = new (nothrow) int[largest];

	if (found == nullptr) {
		cout << "No memory\n";
		return -1;
	}

	for (int val : array) {
		if (found[val] == 1) {
			return val;
		}

		found[val] = 1;
	}

	return -1;
}

int main()
{
	int dupe = ohN();

	if (dupe == -1) {
		cout << "No duplicates\n";
	} else {
		cout << "Dupe found: " << dupe << "\n"; 
	}
	
}
