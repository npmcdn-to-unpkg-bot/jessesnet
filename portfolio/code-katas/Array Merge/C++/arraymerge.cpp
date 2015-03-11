#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

/*
	NEXT 
		- Test different array sizes
		- Do it with two unsorted arrays
*/

int main()
{
	// less than means comes first
	// capital letters considered greater than
	
	std::array<string,5> array1;
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
	
	std::array<string,10> merged;

	int max1 = array1.size();
	int max2 = array2.size();

	int items = max1 + max2;
	int sorted=0, i=0, j=0;

	while (sorted < items) {

		if (i >= max1) {
			merged[sorted] = array2[j];
			j++;
		} else if (j >= max2) {
			merged[sorted] = array1[i];
			i++;
		} else if (array1[i] < array2[j]) {
			merged[sorted] = array1[i];
			i++;
		} else {
			merged[sorted] = array2[j];
			j++;
		}

		sorted++;
	}
	
	int order = 1;

	for (string fruit : merged) {
		cout << order << ") " << fruit << "\n";
		order++;
	}

	
	return 1;
}

