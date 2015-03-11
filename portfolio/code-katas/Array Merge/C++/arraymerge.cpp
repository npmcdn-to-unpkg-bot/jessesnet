#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

/*
	Task - Given two sorted arrays, denoted as array1 and array2, please merge them into array1 and
           keep the merged array sorted. Suppose there is sufficient vacant memory at the end of array1 
           to accommodate elements of array2.
*/

int main()
{
	// less than means comes first
	// capital letters considered greater than

	std::array<string,10> array1;
	array1[0] = "apples";
	array1[1] = "carrots";
	array1[2] = "lettuce";
	array1[3] = "mango";
	array1[4] = "maple";

	std::array<string,5> array2;
	array2[0] = "bannana";
	array2[1] = "brocolli";
	array2[2] = "couliflower";
	array2[3] = "mayonese";
	array2[4] = "olives";
		
	// dont want all 10 values
	// std::array<string,10> arrayc = array1;
	
	std::array<string,5> arrayc;
	std::copy(array1.begin(), array1.begin()+5, arrayc.begin());

	return 1;
}

