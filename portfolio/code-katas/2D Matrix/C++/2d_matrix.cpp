#include <iostream>
#include <vector>
#include <algorithm> 
#include <chrono>

using namespace std;
using namespace std::chrono;

// g++ -std=c++11 array_duplication.cpp -o out
// ./out

int m[4][4]=
{
    {1,2,8,14},
	{2,4,9,12},
	{4,7,10,13},
	{6,8,11,15},
};

int first(int find);
int second(int find);

int main()
{
	int i;

	cout << "Search for: ";
	cin >> i;

	if (i < 1) {
		cout << "Invalid input \n";
		exit(1);
	}
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	try {
		first(i);
		cout << "Found with first()! \n";
	} catch(...) {
		cout << "Not found\n";
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	try {
		second(i);
		cout << "Found with second()! \n";
	} catch(...) {
		cout << "Not found\n";
	}	

	high_resolution_clock::time_point t3 = high_resolution_clock::now();

	auto step1 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	auto step2 = std::chrono::duration_cast<std::chrono::microseconds>( t3 - t2 ).count();
	
	cout << "first() took " << step1 << "\n";
	cout << "second() took " << step2 << "\n";
}

int second(int find)
{
	// start at the end, if find < start move to the next row
	int len = (sizeof(m)/sizeof(*m));

	for (int i=len; i>-1; --i) {
		if (find == m[i][0]) {
			return m[i][0];
		}	
		if (find < m[i][0]) {
			continue;
		}

		int sub_len = (sizeof(m[i])/sizeof(*m[i]));
		int *p = std::find (m[i], m[i]+sub_len, find);

		if (p != m[i]+sub_len) {
			return *p;
		}
	}

	throw false;
}

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

    throw false;
}

