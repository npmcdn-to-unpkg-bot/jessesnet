#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// g++ -std=c++11 array_duplication.cpp -o out
// ./out

int m[4][4]=
{
    {1,2,8,9},
	{2,4,9,12},
	{4,7,10,13},
	{6,8,11,15},
};

int first(int find)
{
	vector<int> v;

	// flatten the matrix
	for (int i=0; i<4; i++) {
    	for (int j=0; j<4; j++) {
    		v.push_back(m[i][j]);
    	}
    }

	// sort the matrix
    if (!std::is_sorted(v.begin(),v.end())) {
    	std::sort(v.begin(), v.end());
    }

	// search the matrix
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), find);

    if (it != v.end()) {
    	return *it;
    }

    throw 0;
}

int main()
{
	int i;

	cout << "Search for: ";
	cin >> i;

	try {
		first(i);
		cout << "Found with first()! \n";
	} catch(...) {
		cout << "Not found\n";
	}	
}
