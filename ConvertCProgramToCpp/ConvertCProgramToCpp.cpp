// Convert this program to C++
// change to one line comments

// change to C++ io
#include <iostream>
#include <vector>

using namespace std;
// change defines of constants to const
const int N = 40;

// inline any short function
inline void sum(int *p, int n, vector <int> V)
{
	*p = 0;

	for(int i=0; i<n; i++ )
		*p += V[i];

}

int main()
{
	int accum =0;
	// change array to vector<>
	vector <int> data;

	for(int i=0; i<N; ++i)
		data.push_back(i);

	sum(& accum, N, data);
	cout << "Sum is " << accum ;
	return 0;
}
