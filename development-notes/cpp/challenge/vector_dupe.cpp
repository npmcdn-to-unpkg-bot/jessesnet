#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

vector<int> array {2,94,8,9,1,83,9,21,47,28,18,94};

int ohN()
{
	vector<int> found (array.size());
	
	/*
	for (int i=0; i<array.size(); i++) {
		if (found[array[i]] == 1) {
			return array[i];
		}

		found[array[i]] = 1;
	}
	*/

	for (int val : array) {
		if (found[val] == 1) {
			return val;
		}

		found[val] = 1;
	}
}

int main()
{
	//cout << "start";
	int dupe;
	dupe = ohN();

	cout << dupe << "\n";
	cout << ohN() << "\n";

	//cout << "end";
}

/*
	todo - calling the same function does not reset it
*/
