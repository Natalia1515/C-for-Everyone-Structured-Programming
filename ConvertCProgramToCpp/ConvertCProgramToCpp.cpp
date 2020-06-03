// Convert this program to C++
// change to one line comments

// change to C++ io
#include <iostream>
#include <vector>

using namespace std;
// change defines of constants to const
const int N = 40;

// inline any short function
inline int getSum(vector <int> V)
{
	int sum = 0;

	for(int i=0; i<N; i++ )
		sum += V[i];

	return sum;
}

int main()
{
	// change array to vector<>
	vector <int> V;

	for(int i=0; i<N; i++ )
		V.push_back(i);

	cout << "\n Sum is " << getSum(V);
	return 0;
}
