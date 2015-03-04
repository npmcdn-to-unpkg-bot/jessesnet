#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

/*
	- arrays only hold specific types of ojects, and are of fixed size
	- can have better performance than a vector
	- can have an array of pointers but not references
	- when using an array the compiler generally converts array to pointer
	- pointers are also iterators so can move to next element with ++
	- you can use an array to init a vector
*/
int main()
{
	int scores[10];
	int numbers[3] = {13,45,33};

	// cannot assign one array to another

	int photos[3];
	photos[0] = 123;
	cout << photos[0] << "\n";
	photos[-1] = 342; // can have negative keys
	cout << photos[-1] << "\n";	
}

