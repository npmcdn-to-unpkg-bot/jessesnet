#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 array_duplication.cpp -o out
// ./out

int array[] = {12342,923422,234278,23429,923422,23421,242342,242342};

int duplicate()
{
	int largest = 0;

	for (int val : array) {
		if (val > largest) {
			largest = val;
		}
	}

	// int* found = new int[largest]; // if allocation fails, an exception is thrown 
	int *found = new (nothrow) int[largest];

	if (found == nullptr) {
		cout << "No memory\n";
		delete[] found;
		found=0;
		return -1;
	}

	for (int val : array) {
		if (found[val] == 1) {
			delete[] found;
			found=0;
			return val;
		}

		found[val] = 1;
	}

	delete[] found;
	found=0;
	return -1;
}

int main()
{
	int dupe = duplicate();

	if (dupe == -1) {
		cout << "No duplicates\n";
	} else {
		cout << "Dupe found: " << dupe << "\n"; 
	}
	
}
