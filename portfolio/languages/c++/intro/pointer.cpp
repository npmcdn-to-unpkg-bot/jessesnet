#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

/*
	- http://www.cplusplus.com/doc/tutorial/pointers/

	- useful for having multiple vars point to same large space in memory
	- passing variables by reference is done with pointers
	- can use large data structures outside of the defined scope
	- Get in the habit of assigning your pointers to 0 both when they are declared 
	  (unless assigned to another address), and after they are deleted. It will save you a lot of grief.
*/
int main()
{	
	int var = 1;
	int *ptr;
	
	// set the pointer equal to the reference (memory location) of the var
	ptr = &var;

	cout << ptr << "\n"; // shows memory address
	cout << *ptr << "\n"; // shows the value, * is dereference

	// can set the actual value
	*ptr = 5;
	// which changes the original variable name
	cout << var << "\n";

	// dynamic memory
	int *ptrs = new int;
	cout << *ptrs << "\n"; // defaults to a value of 0
	cout << ptrs << "\n"; // address is on the heap

	exit(1);
}

